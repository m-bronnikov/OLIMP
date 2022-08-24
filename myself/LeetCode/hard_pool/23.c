#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

#define append_from(to, from)   \
do{                             \
    to->next = from;            \
    to = from;                  \
    from = to->next;            \
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


Node* mergeKLists(Node** lists, int size){
    if(size <= 1)
    {
        return size ? lists[0] : NULL;
    }
    
    int half = size >> 1;

    // merge by pairs
    for(int i = 0; i < half; ++i)
    {
        lists[i] = mergeTwoLists(lists[i], lists[i + half]);
    }

    // add last list to array if not in pair
    if(size & 1)
    {
        lists[half++] = lists[size - 1]; 
    }

    return mergeKLists(lists, half);
}



int main()
{
    Node node1_3 = {4, NULL};
    Node node1_2 = {2, &node1_3};
    Node node1_1 = {1, &node1_2};

    Node node2_3 = {4, NULL};
    Node node2_2 = {3, &node2_3};
    Node node2_1 = {1, &node2_2};

    Node node3_3 = {7, NULL};
    Node node3_2 = {2, &node3_3};
    Node node3_1 = {0, &node3_2};

    Node* arr[] = {&node1_1, &node2_1, &node3_1};
    Node* list = mergeKLists(arr, 3);

    while(list)
    {
        printf("%d -> ", list->val);
        list = list->next;
    }
    printf("NULL \n");

    return 0;
}