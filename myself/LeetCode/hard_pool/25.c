#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

Node* reverseKGroup(Node* head, int k){
    Node dummy = {-1, head};

    Node* left = &dummy;
    while(1)
    {
        // go over k nodes
        Node* right = left;
        for(int i = 0; right && i < k; ++i)
        {
            right = right->next;
        }

        // if tail less than k nodes let's break
        if(!right){
            break;
        }


        Node* prev = left->next;
        Node* next = prev->next;

        // reconnect borders
        prev->next = right->next;
        left->next = right;
        left = prev;

        // reverse connections
        for(int i = 1; i < k; ++i)
        {
            Node* tmp = next->next;
            next->next = prev;
            prev = next;
            next = tmp;
        }
    }

    return dummy.next;
}


int main()
{
    Node node7 = {7, NULL};
    Node node6 = {6, &node7};
    Node node5 = {5, &node6};
    Node node4 = {4, &node5};
    Node node3 = {3, &node4};
    Node node2 = {2, &node3};
    Node node1 = {1, &node2};

    Node* list = reverseKGroup(&node1, 7);

    while(list)
    {
        printf("%d -> ", list->val);
        list = list->next;
    }
    printf("NULL \n");

    return 0;
}