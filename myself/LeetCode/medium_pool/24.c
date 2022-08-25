#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

Node* swapPairs(Node* head){
    Node dummy = {-1, head};

    Node* node = &dummy;
    while(node->next && node->next->next)
    {
        Node* first = node->next;
        Node* second = first->next;

        first->next = second->next;
        second->next = first;
        node->next = second;

        node = first;
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

    Node* list = swapPairs(&node1);

    while(list)
    {
        printf("%d -> ", list->val);
        list = list->next;
    }
    printf("NULL \n");

    return 0;
}
