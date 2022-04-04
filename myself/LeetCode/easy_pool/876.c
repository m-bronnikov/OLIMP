#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// forward declaration
typedef struct ListNode ListNode;


ListNode* middleNode(ListNode* head){
    // it's guaranteed there is more than 1 node, so head->next is safe
    ListNode* node = head->next;
    ListNode* mid = head;
    int flag = 0;

    // update middle through each 2 nodes
    while(node)
    {
        mid = (flag ^= 1) ? mid->next : mid;
        node = node->next;
    }

    return mid;
}


int main()
{
    ListNode node4 = {0, NULL};
    //ListNode node3 = {2, &node4};
    ListNode node2 = {1, &node4};
    ListNode node1 = {3, &node2};

    printf("%d\n", middleNode(&node1)->val);

    return 0;
}
