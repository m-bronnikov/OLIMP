#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// forward declaration
typedef struct ListNode ListNode;

ListNode* swapNodes(ListNode* head, int k){
    // compute length of the list
    int size = 0;
    {
        ListNode* node = head;
        while(node)
        {
            ++size;
            node = node->next;
        }
    }

    // use indxes from 0
    int k1 = (k - 1) > (size - k) ? (size - k) : (k - 1);
    int k2 = size - k1 - 1;
    if(k1 == k2)
        return head;

    // fake helping first element
    ListNode head_term = {-1, head};

    // fake helping element after first swap candidate
    ListNode sepr_term = {-1, NULL};

    // find first swap element
    ListNode* before_first = &head_term;
    for(int i = 0; i < k1; ++i)
    {
        before_first = before_first->next;
    }
    ListNode* first = before_first->next;

    // insert fake separating node
    sepr_term.next = first->next;
    first->next = &sepr_term;

    // find second swap element
    ListNode* before_second = &sepr_term;
    for(int i = k1 + 1; i < k2; ++i)
    {
        before_second = before_second->next;
    }
    ListNode* second = before_second->next;


    // reconnect nodes
    before_first->next = second;
    before_second->next = first;

    first->next = second->next;
    second->next = sepr_term.next; // skip separator node
    
    if(k1 == 0)
        head = second;
    
    return head;
}

int main()
{
    ListNode node5 = {5, NULL};
    ListNode node4 = {4, &node5};
    ListNode node3 = {3, &node4};
    ListNode node2 = {2, &node3};
    ListNode node1 = {1, &node2};


    printf("%d\n", swapNodes(&node1, 1)->val);

    return 0;
}