#include <iostream>

#include <stack>

struct Node
{
    int value = 0;
    Node* left = nullptr;
    Node* right = nullptr;
};


void search(const Node* node, int elem, int k)
{
    std::stack<const Node*> path;

    // search near greater or equal
    while(node)
    {
        if(elem < node->value)
        {
            path.push(node);
            node = node->left;
            continue;
        }
        else
        {
            node = node->right;
            continue;
        }
    }

    // if no greater exist throw
    if(path.empty())
    {
        throw std::runtime_error("No such value!");
    }

    // print first k greater elems
    while(!path.empty() && k)
    {
        node = path.top();
        path.pop();

        // print current
        {
            std::cout << node->value << std::endl;
            --k;
        }


        // process right branch: add all left (include root) to stack
        node = node->right;
        while(node)
        {
            path.push(node);
            node = node->left;
        }
    }
}


int main()
{
    Node node3 = {3, nullptr, nullptr};
    Node node7 = {7, nullptr, nullptr};
    Node node5 = {5, &node3, &node7};

    Node node22 = {22, nullptr, nullptr};

    Node node13 = {13, nullptr, nullptr};
    Node node17 = {17, nullptr, nullptr};
    Node node15 = {15, &node13, &node17};

    Node node20 = {20, &node15, &node22};

    Node node10 = {10, &node5, &node20};

    search(&node10, 4, 5);

    return 0;
}