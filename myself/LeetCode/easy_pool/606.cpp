#include <iostream>

#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
    void recursive(TreeNode* node, std::stringstream& is)
    {
        is << node->val;
        if(!node->left && !node->right){
            return;
        }
        
        is << '(';
        node->left ? recursive(node->left, is) : (void) 0;
        is << ')';

        if(!node->right){
            return;
        }

        is << '(';
        recursive(node->right, is);
        is << ')';
    }

public:
    std::string tree2str(TreeNode* root) 
    {
        std::stringstream is;
        recursive(root, is);

        return is.str();
    }
};

int main()
{
    TreeNode node_2_0(4, nullptr, nullptr);
    TreeNode node_2_1(5, nullptr, nullptr);
    TreeNode node_2_2(6, nullptr, nullptr);
    TreeNode node_2_3(7, nullptr, nullptr);

    TreeNode node_1_0(2, &node_2_0, &node_2_1);
    TreeNode node_1_1(3, &node_2_2, &node_2_3);

    TreeNode node_0_0(1, &node_1_0, &node_1_1);

    std::cout << Solution().tree2str(&node_0_0) << std::endl;
    return 0;
}