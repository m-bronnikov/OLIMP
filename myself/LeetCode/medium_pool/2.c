#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// forward declaration
typedef struct ListNode ListNode;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
    // we will accumulate result in first list
    ListNode *head = l1;

    while(1)
    {
        int add_to_next = 0;

        l1->val += l2->val;
        if(l1->val > 9)
        {
            l1->val -= 10;
            add_to_next = 1;
        }

        // case 1: elems of both lists exist
        if(l1->next && l2->next)
        {
            l1 = l1->next;
            l1->val += add_to_next;

            l2 = l2->next;
            continue;
        }

        // case 2: elems of first list exist, elems of second list not exist
        if(l1->next && !l2->next)
        {
            l1 = l1->next;
            l1->val += add_to_next;

            // break if next iterations are redundant
            if(l1->val < 10)
            {
                break;
            }

            // make zero and keep l2 as is
            l2->val = 0;
            continue;
        }

        // case 3: elems of first list not exist, elems if second list exist
        if (!l1->next && l2->next)
        {
            // connect l1 to l2's next
            l1->next = l2->next;
            l2->next = NULL;
            
            l1 = l1->next;
            l1->val += add_to_next;
            
            // break if next iterations are redundant
            if(l1->val < 10)
            {
                break;
            }

            // make zero and keep l2 as is
            l2->val = 0;
            continue;
        }

        // case 4: elems of both lists not exist
        if (!l1->next && !l2->next)
        {
            if(add_to_next)
            {
                // make additional last elem from l2
                l2->val = add_to_next;
                l1->next = l2;
            }

            break;
        }
    }

    return head;
}



int main()
{
    //ListNode node1_5 = {5, NULL};
    //ListNode node1_4 = {4, &node1_5};
    ListNode node1_3 = {9, NULL};
    ListNode node1_2 = {4, &node1_3};
    ListNode node1_1 = {2, &node1_2};

    // ListNode node2_5 = {5, NULL};
    ListNode node2_4 = {9, NULL};
    ListNode node2_3 = {4, &node2_4};
    ListNode node2_2 = {6, &node2_3};
    ListNode node2_1 = {5, &node2_2};

    ListNode* head = addTwoNumbers(&node1_1, &node2_1);

    printf("%d", head->val);
    while (head->next)
    {
        head = head->next;
        printf(" -> %d", head->val);
    }
    printf("\n");

    return 0;
}
