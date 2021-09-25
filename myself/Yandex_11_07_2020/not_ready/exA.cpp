#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

char make_change(char c, int r){
    if(c - r < 'a'){
        return c - r + ('z' - 'a' + 1);
    }
    return c - r;
}


class node{
public:
    node(){
        c = '0';
        end = -1;
    }

    node(char ch){
        c = ch;
        end = -1;
    }

    void set_string(string& str, int i){
        node* now = this;

        char min = str[0] - 'a';

        for(auto ch : str){
            char inb = make_change(ch, min);
            if(now->child.find(inb) != now->child.end()){
                now = &now->child[inb];
            }else{
                now->child[inb] = node(inb);
                now = &now->child[inb];
            }
        }

        now->end = i;
    }

    int get_idx(string& str){
        char min = str[0] - 'a';
        node* now = this;

        for(auto ch : str){
            now = &now->child[make_change(ch, min)];
        }

        return now->end;
    }

    char c;
    map<char, struct node> child;
    int end;
};

/*
void separate(string& inpt, vector<string>& ans){
    string temp;
    for(auto c : inpt){
        if(c == ' '){
            ans.push_back(temp);
            temp.clear();
        }else{
            temp.push_back(c);
        } 
    }
    if(temp != ""){
        ans.push_back(temp);
    }
}
*/
/*
void change(vector<string>& dict){
    char min = 100;
    for(auto str : dict){
        for(auto c : str){
            min = min <= c - 'a' ? min : c - 'a';
        }
        for(size_t i = 0; i < str.size(); ++i){
            str[i] -= min;
        }
    }
}
*/

/*
char make_change(char c, int r){
    if(c + r > 'z'){
        return c + r - ('z' - 'a' + 1);
    }
    return c + r;
}



bool check(string& s1, string& s2){
    if(s1.size() != s2.size()){
        return false;
    }

    int r = s2[0] - s1[0];
    if(r < 0){
        r += 'z' - 'a' + 1;
    }
    //cout << (r) << ' ';
    for(int i = 1; i < s1.size(); ++i){
        if(s2[i] != make_change(s1[i], r)){
            //cout << make_change(s1[i], r) << endl;
            return false;
        }
    }

    return true;
}

*/


int main(){
    ios_base::sync_with_stdio(false);
    vector<string> dict;
    string input;
    getline(cin, input, '\n');

    string temp;
    node bor;
    bor.c = '0';

    // split
    int i = 0;
    for(auto c : input){
        if(c == ' '){
            dict.push_back(temp);
            bor.set_string(temp, i++);
            temp.clear();
        }else{
            temp.push_back(c);
        } 
    }
    if(temp != ""){
        dict.push_back(temp);
        bor.set_string(temp, i++);
    }

    int n;
    
    cin >> n;

    // search
    for(i = 0; i < n; ++i){
        cin >> temp;
        //cout << "idx: " << bor.get_idx(temp) << endl;
        cout << dict[bor.get_idx(temp)] << endl;
    }

    return 0;
}