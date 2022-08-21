#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


typedef struct ListNode Node;

Node* removeNthFromEnd(Node* head, int n){
    Node term = {-1, head};

    // skip first n nodes
    while(n--)
    {
        head = head->next;
    }

    // find tail
    Node* node = &term;
    while (head)
    {
        head = head->next;
        node = node->next;   
    }


    node->next = node->next->next;
    return term.next;
}

int main()
{
    // no test =(
    return 0;
}