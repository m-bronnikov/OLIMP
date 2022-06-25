#include <iostream>
#include <string>

#include <vector>
#include <array>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cstring>

constexpr int idx_of_a = 1;
constexpr int alphabet_size = ('z' - 'a' + 1) + 1; // lowercase english letters with '\0'

int char_to_num(char ch)
{
    return ch ? (ch - 'a' + idx_of_a) : 0;
}

template <typename T>
void sort_and_remove_duplicates(std::vector<T>& arr)
{
    if(arr.empty()) return;

    // sort
    std::sort(begin(arr), end(arr));

    // remove dups and resize
    int new_size = 1;
    for(int i = 1; i < arr.size(); ++i)
    {
        if(arr[i] == arr[new_size - 1])
            continue;

        arr[new_size++] = arr[i];
    }
    arr.resize(new_size);
}


struct Symbol{
    Symbol() = default;
    Symbol(char ch) : letter(ch) {}
    Symbol(const char* position_in_pattern);

    static Symbol create_full_clini_star();

    bool is_all_letters() const { return letter == '.'; }
    int get_length() const { return is_clini ? 2 : 1; }

    bool is_clini = false;
    char letter;
};

Symbol::Symbol(const char* position_in_pattern)
{
    letter = *position_in_pattern;
    if(*(position_in_pattern + 1) == '*')
    {
        is_clini = true;
    }
}


Symbol Symbol::create_full_clini_star()
{
    Symbol star('.');
    star.is_clini = true;
    return star;
}


std::vector<Symbol> string_to_symbols(const std::string& pattern)
{
    std::vector<Symbol> symbols;
    symbols.reserve(pattern.size() + 1);

    int idx = 0;
    while(idx < pattern.size())
    {
        // convert chars to symbol
        Symbol symbol(&pattern[idx]);
        symbols.push_back(symbol);
        idx += symbol.get_length();
    }

    // create and push symbol for terminal
    Symbol terminal('\0');
    symbols.push_back(terminal);

    return symbols;
}


// speed up step
static void merge_clini_stars(std::vector<Symbol>& pattern)
{
    // first pass: eliminate '.*' with other stars in a row
    int i = 0;
    int j = 0;
    while(i < pattern.size())
    {
        if(!pattern[i].is_clini)
        {
            pattern[j++] = pattern[i++];
            continue;
        }

        int k = i;
        bool mega_star_detected = false;
        while(k < pattern.size() && pattern[k].is_clini)
        {
            mega_star_detected = mega_star_detected || pattern[k].is_all_letters();
            ++k;
        }

        if(mega_star_detected)
        {
            pattern[j++] = Symbol::create_full_clini_star();
            while(i < k) { ++i; }
            continue;
        }

        while(i < k)
        {
            pattern[j++] = pattern[i++];
        }
    }
    pattern.resize(j);

    // second pass: eliminate equal stars series
    i = 1;
    j = 1;
    while(i < pattern.size())
    {
        if(pattern[i].is_clini && pattern[j - 1].is_clini && pattern[i].letter == pattern[j - 1].letter)
        {
            ++i;
            continue;
        }

        pattern[j++] = pattern[i++];
    }
    pattern.resize(j);
}


struct NFAState{
    using state_num = int; // index on state in internal array of NFA

    explicit NFAState(state_num idx) : num(idx) {}

    static constexpr int eps_connection_idx = alphabet_size;

    state_num num;
    std::array<std::vector<state_num>, alphabet_size + 1> char2states; // +1 for temporary eps-connections
};

class NFA{
friend class DFA;

public:
    explicit NFA(const std::vector<Symbol>& pattern);
    bool is_matches(const std::string& str) const;

    void destroy() { states.clear(); }

private:
    void eliminate_eps_connections();
    void create_connections_by_symbol(NFAState::state_num state_idx, Symbol symbol);

private:
    bool is_matches_internal(const char* str, const NFAState& state) const;

private:
    NFAState::state_num final_state;
    std::vector<NFAState> states;
};


void NFA::create_connections_by_symbol(NFAState::state_num state_idx, Symbol symbol)
{
    // create new state
    NFAState::state_num new_state_num = states.size();
    states.push_back(NFAState{new_state_num});

    // take current state
    NFAState& state = states[state_idx];

    // create eps-connection at first if is clini
    if(symbol.is_clini)
    {
        state.char2states[NFAState::eps_connection_idx].push_back(new_state_num);
    }

    // if clini => connect to itself
    NFAState::state_num state_to_connect = symbol.is_clini ? state.num : new_state_num;

    // if single letter connect only one
    if(!symbol.is_all_letters())
    {
        state.char2states[char_to_num(symbol.letter)].push_back(state_to_connect);
        return;
    }

    // otherwise connect all letters except terminal
    for(int i = idx_of_a; i < alphabet_size; ++i)
    {
        state.char2states[i].push_back(state_to_connect);
    }
}


NFA::NFA(const std::vector<Symbol>& pattern)
{
    states.push_back(NFAState{0});

    for(int i = 0; i < pattern.size(); ++i)
    {
        // create connections
        create_connections_by_symbol(i, pattern[i]);
    }

    // final state is latest state
    final_state = states.back().num;

    // convert DFA with eps connections to NFA
    eliminate_eps_connections();
}

void NFA::eliminate_eps_connections()
{
    for(NFAState& state : states)
    {
        std::vector<NFAState::state_num>& eps_connections = state.char2states[NFAState::eps_connection_idx];
        while(!eps_connections.empty())
        {
            NFAState::state_num eps_connect = eps_connections.back();
            eps_connections.pop_back();

            NFAState& connected_state = states[eps_connect];

            // add all connections from connected with eps state by transitivity
            for(int idx = 0; idx < state.char2states.size(); ++idx)
            {
                // note connected_state.char2states.size() must be 0 or 1, but iteration is more safe
                for(NFAState::state_num new_connect : connected_state.char2states[idx])
                {
                    state.char2states[idx].push_back(new_connect);
                }
            }
        }
    }
}


bool NFA::is_matches(const std::string& str) const
{
    return is_matches_internal(str.c_str(), states[0]);
}


bool NFA::is_matches_internal(const char* str, const NFAState& state) const
{
    const auto& possible_states = state.char2states[char_to_num(*str)];

    // no matches if no next state exist
    if(possible_states.empty())
        return false;

    // check end of string
    // don't check does next state is final since only final state could be accessed by terminal symbol
    if(*str == '\0')
        return true;

    for(NFAState::state_num next_state_num : possible_states)
    {
        if(is_matches_internal(str + 1, states[next_state_num]))
            return true;
    }

    return false;
}


struct DFAState{
    using state_num = int; // index on state in internal array of NFA

    explicit DFAState(state_num idx);

    static constexpr int fail_connection_idx = -1;
    
    bool is_final = false;
    state_num num;
    std::array<state_num, alphabet_size> char2state;
};


DFAState::DFAState(state_num idx) : num(idx)
{
    // initialize with fail connection (TODO constexpr)
    for(auto& state : char2state)
    {
        state = fail_connection_idx;
    }
}


class DFA{
public:
    explicit DFA(const NFA& nfa);
    bool is_matches(const std::string& str) const;

    void destroy() { states.clear(); }

private:
    // merged state for thompson algorithm aplication
    using merged_state = std::vector<NFAState::state_num>;

    struct vector_hash
    {
        size_t operator()(const merged_state& key) const;
    };

    struct vector_equal
    {
        bool operator()(const merged_state& lhs, const merged_state& rhs) const;
    };

    void construct_with_thompson_algorithm(const NFA& nfa);

private:
    std::vector<DFAState> states;
};


size_t DFA::vector_hash::operator()(const merged_state& key) const
{
    size_t hash = 0;
    for(const NFAState::state_num num : key)
    {
        hash ^= std::hash<NFAState::state_num>()(num);
    }
    return hash;
}

bool DFA::vector_equal::operator()(const merged_state& lhs, const merged_state& rhs) const
{
    if(lhs.size() != rhs.size()) return false;

    return std::memcmp(lhs.data(), rhs.data(), lhs.size() * sizeof(NFAState::state_num)) == 0;
}


DFA::DFA(const NFA& nfa)
{
    // construct equialent DFA from NFA using Thompson algorithm
    construct_with_thompson_algorithm(nfa);
}

void DFA::construct_with_thompson_algorithm(const NFA& nfa)
{
    std::unordered_map<merged_state, DFAState::state_num, vector_hash, vector_equal> thompson_visited;
    std::queue<merged_state> queue;

    // create initial state
    merged_state initial_merged_state = {0};
    states.push_back(DFAState{0});

    // mark as visited and push to queue
    thompson_visited[initial_merged_state] = states.back().num;
    queue.push(std::move(initial_merged_state));

    while(!queue.empty())
    {
        const merged_state merged_nfa_state = std::move(queue.front());
        queue.pop();

        DFAState::state_num dfa_state_num = thompson_visited[merged_nfa_state];

        // check if final
        const bool is_final = (std::find(begin(merged_nfa_state), end(merged_nfa_state), nfa.final_state) != end(merged_nfa_state));
        states[dfa_state_num].is_final = is_final;

        // for each character
        for(int i = 0; i < alphabet_size; ++i)
        {
            merged_state new_merged_state;

            for(NFAState::state_num nfa_state_num : merged_nfa_state)
            {
                const NFAState& nfa_state = nfa.states[nfa_state_num];
                for(NFAState::state_num connect : nfa_state.char2states[i])
                {
                    new_merged_state.push_back(connect);
                }
            }
 
            if(new_merged_state.empty())
            {
                continue;
            }
            sort_and_remove_duplicates(new_merged_state);

            auto const it = thompson_visited.find(new_merged_state);
            DFAState::state_num new_dfa_state_num;

            // if exist take dfa state num
            if(it != thompson_visited.end())
            {
                new_dfa_state_num = it->second;
            }
            // else create new dfa state, mark as visited and push to queue
            else
            {
                new_dfa_state_num = states.size();
                states.push_back(DFAState{new_dfa_state_num});
                thompson_visited[new_merged_state] = new_dfa_state_num;
                queue.push(std::move(new_merged_state));
            }

            // connect
            states[dfa_state_num].char2state[i] = new_dfa_state_num;
        }
    }
}

bool DFA::is_matches(const std::string& str) const
{
    const DFAState* state = &states[0];

    for(char c : str)
    {
        DFAState::state_num next_state_num = state->char2state[char_to_num(c)];
        if(next_state_num == DFAState::fail_connection_idx)
        {
            return false;
        }

        state = &states[next_state_num];
    }

    // check terminal symbol
    DFAState::state_num last_state_num = state->char2state[char_to_num('\0')];
    return last_state_num != DFAState::fail_connection_idx && states[last_state_num].is_final;
}


class Solution {
public:
    bool isMatch(std::string& str, std::string& pat) {
        // 0. change representation
        std::vector<Symbol> symbols = string_to_symbols(pat);
        pat.clear();

        // 1. optimize symbols
        merge_clini_stars(symbols);

        // 2. create NFA
        NFA nfa(symbols);
        symbols.clear();

        // 3. match strings using nfa
        return nfa.is_matches(str);

        // It's possible to create DFA from NFA, but it's better to do in case of many strings for single pattern

        // 3. create DFA
        // DFA dfa(nfa);
        // nfa.destroy();

        // 4. match strings using dfa
        // return dfa.is_matches(str);
    }
};


int main()
{
    std::string a = "bab";
    std::string b = "a*b*a*a*c*aa*c*bc*";
    
    std::cout << Solution().isMatch(a, b) << std::endl;
    return 0;
}
