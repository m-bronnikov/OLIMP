#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    bool is_connected(const string& lhs, const string& rhs)
    {
        int diff = 0;

        for(int i = 0; i < 8; ++i)
        {
            diff += (lhs[i] == rhs[i]) ? 0 : 1;
        }

        return diff == 1;
    }

    struct Frame{
        int idx = -1;
        int step = -1;
    };

    int bfs(const vector<vector<int>>& g, int start, int end)
    {
        vector<char> colors(g.size(), 0);

        queue<Frame> frames;
        frames.push({start, 0});
        colors[0] = 1;

        while(!frames.empty())
        {
            Frame curr = frames.front();
            frames.pop();

            if(curr.idx == end)
            {
                return curr.step;
            }

            for(int next : g[curr.idx])
            {
                if(colors[next])
                {
                    continue;
                }

                frames.push({next, curr.step + 1});
                colors[next] = 1;
            }
        }

        return -1;
    }


public:
    int minMutation(const string& start, const string& end, vector<string> bank) {
        vector<vector<int>> graph(bank.size() + 1);
        
        int end_idx = 0;
        for(int i = 0; i < bank.size(); ++i)
        {
            if(!end_idx && end == bank[i])
            {
                end_idx = i + 1;
            }

            if(is_connected(start, bank[i]))
            {
                graph[0].push_back(i + 1);
            }

            for(int j = i; j < bank.size(); ++j)
            {
                if(is_connected(bank[i], bank[j]))
                {
                    graph[i + 1].push_back(j + 1);
                    graph[j + 1].push_back(i + 1);
                }
            }
        }

        if(!end_idx)
        {
            return -1;
        }

        return bfs(graph, 0, end_idx);
    }
};


int main()
{
    string start = "AACCGGTT";
    string end = "AAACGGTA";
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};

    std::cout << Solution().minMutation(start, end, bank) << std::endl;

    return 0;
}