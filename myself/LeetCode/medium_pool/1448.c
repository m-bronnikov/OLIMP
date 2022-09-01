#include <stdio.h>

#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode Node;

int goodNodesRecoursive(Node* node, int max_value)
{    
    int count = 0;
    if(node->val >= max_value){
        count = 1;
        max_value = node->val;
    }

    if(node->left)
    {
        count += goodNodesRecoursive(node->left, max_value);
    }

    if(node->right)
    {
        count += goodNodesRecoursive(node->right, max_value);
    }

    return count;
}

int goodNodes(Node* root){
    return goodNodesRecoursive(root, INT_MIN);
}

int main(){
    // without test
    return 0;
}