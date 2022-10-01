#include <iostream>

#include <vector>


class Node {
public:
    int val;
    std::vector<Node*> children;
};


class Solution {
private:
    void order_recursive(Node* node, unsigned lvl, std::vector<std::vector<int>>& levels)
    {
        if(!node){
            return;
        }

        if(lvl == levels.size())
        {
            levels.push_back({});
        }

        levels[lvl].push_back(node->val);

        for(Node* chld : node->children)
        {
            order_recursive(chld, lvl + 1, levels);
        }
    }

public:
    std::vector<std::vector<int>> levelOrder(Node* root) {
        std::vector<std::vector<int>> levels;
        order_recursive(root, 0, levels);
        return levels;
    }
};

int main()
{
    // without test =(
    return 0;
}