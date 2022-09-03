#include <iostream>

#include <vector>

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
    void pre_order_traversal(TreeNode* node, unsigned level, std::vector<int>& counts, std::vector<double>& avgs)
    {
        if(!node){
            return;
        }

        if(level == counts.size())
        {
            counts.push_back(0);
            avgs.push_back(0.0);
        }

        avgs[level] = avgs[level] * counts[level] + node->val;
        ++counts[level];
        avgs[level] /= counts[level];

        pre_order_traversal(node->left, level + 1, counts, avgs);
        pre_order_traversal(node->right, level + 1, counts, avgs);
    }

public:
    std::vector<double> averageOfLevels(TreeNode* root) {
        std::vector<int> count_level;
        std::vector<double> avg_level;

        pre_order_traversal(root, 0, count_level, avg_level);
        return avg_level;
    }
};

int main()
{
    TreeNode node_2_0(0, nullptr, nullptr);
    TreeNode node_2_1(1, nullptr, nullptr);
    TreeNode node_2_2(2, nullptr, nullptr);
    TreeNode node_2_3(3, nullptr, nullptr);

    TreeNode node_1_0(0, &node_2_0, &node_2_1);
    TreeNode node_1_1(1, &node_2_2, &node_2_3);

    TreeNode node_0_0(0, &node_1_0, &node_1_1);

    auto const res = Solution().averageOfLevels(&node_0_0);
    for(double v : res)
    {
        std::cout << v << std::endl;
    }

    return 0;
}