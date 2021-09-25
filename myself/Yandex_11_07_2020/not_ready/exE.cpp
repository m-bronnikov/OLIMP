#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

typedef struct node{
    struct node* left;
    struct node* right;
    int p;
}node;

/*
int main(){
    ios_base::sync_with_stdio(false);
    list<int> perm;
    int n, m, mode;
    cin >> n >> m >> mode;
    --mode;
    for(int i = 1; i <= m; ++i){
        perm.push_back(i);
    }

    if(mode){
        for(int i = 0; i < n; ++i){
            int letter;
            cin >> letter;
            int j = 1;
            auto it = perm.begin();
            //search
            for(; j < letter; ++j){
                ++it;
            }
            letter = (*it);
            cout << letter << " ";
            perm.erase(it);
            perm.push_front(letter);
        }
    }else{
        for(int i = 0; i < n; ++i){
            int letter;
            cin >> letter;
            int j = 1;
            auto it = perm.begin();
            // search
            for(; (*it)!=letter; it++){
                ++j;
            }
            cout << j << " ";
            perm.erase(it);
            perm.push_front(letter);
            
        }
    }

    cout << endl;
    return 0;

}
*/

int main(){
    int n, m, mode;
    cin >> n >> m >> mode;
    --mode;
    vector<node> perms(m);
    node term1;
    term1.p = 0;
    node* now = &term1;
    for(int i = 0; i < m; ++i){
        perms[i].p = i + 1;
        perms[i].left = now;
        now->right = &perms[i];
        now = &perms[i];
    }
    now->right = &term1;
    term1.left = now;

    if(mode){
        for(int i = 0; i < n; ++i){
            int letter;
            cin >> letter;
            int j = 0;
            now = &term1;
            //search
            for(; j < letter; ++j){
                now = now->right;
            }

            cout << now->p << " ";
            
            now->left->right = now->right;
            now->right->left = now->left;
            term1.right->left = now;
            now->right = term1.right;
            term1.right = now;
            now->left = &term1; 
        }
    }else{
        for(int i = 0; i < n; ++i){
            int letter;
            cin >> letter;
            int j = 0;
            now = &term1;
            //search
            for(; now->p != letter; ++j){
                now = now->right;
            }

            cout << j << " ";
            
            now->left->right = now->right;
            now->right->left = now->left;
            term1.right->left = now;
            now->right = term1.right;
            term1.right = now;
            now->left = &term1; 
        }
    }
    cout << endl;
    return 0;
}
