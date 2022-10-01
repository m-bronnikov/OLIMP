#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode Node;

int isZero(Node* node)
{
    return !node->val && !node->left && !node->right;
}

Node* pruneTree(Node* root){
    if(!root)
    {
        return NULL;
    }

    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);

    return isZero(root) ? NULL : root;
}

int main()
{
    Node node_2_0 = {0, NULL, NULL};
    Node node_2_1 = {0, NULL, NULL};
    Node node_2_2 = {0, NULL, NULL};
    Node node_2_3 = {0, NULL, NULL};

    Node node_1_0 = {0, &node_2_0, &node_2_1};
    Node node_1_1 = {0, &node_2_2, &node_2_3};

    Node node_0_0 = {0, &node_1_0, &node_1_1};

    Node* root = pruneTree(&node_0_0);
    printf("%p\n", root);

    return 0;
}