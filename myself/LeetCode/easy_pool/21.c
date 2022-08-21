#include <stdio.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

#define append_from(to, from)   \
do{                             \
    to->next = from;            \
    to = from;                  \
    from = from->next;          \
}while(0)                        

Node* mergeTwoLists(Node* list1, Node* list2)
{
    Node head_node = {0, NULL};
    Node* node = &head_node;

    // merge lists
    while(list1 && list2){
        if(list1->val < list2->val){
            append_from(node, list1);
            continue;
        }

        append_from(node, list2);
    }

    // append tail
    node->next = list1 ? list1 : list2;

    return head_node.next;
}

int main()
{
    Node node1_3 = {4, NULL};
    Node node1_2 = {2, &node1_3};
    Node node1_1 = {1, &node1_2};

    Node node2_3 = {4, NULL};
    Node node2_2 = {3, &node2_3};
    Node node2_1 = {1, &node2_2};

    Node* list = mergeTwoLists(&node1_1, &node2_1);

    while(list)
    {
        printf("%d -> ", list->val);
        list = list->next;
    }
    printf("NULL \n");

    return 0;
}