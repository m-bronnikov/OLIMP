#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// forward declaration
typedef struct ListNode ListNode;

bool isPalindrome(ListNode* head){
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

    int half = size >> 1;

    // revert first half of list and define start nodes for checking
    ListNode *first_start = NULL;
    ListNode *second_start = NULL;
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        for(int i = 0; i < half; ++i)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        first_start = prev;
        second_start = curr;
        if(size & 1)
        {
            second_start = curr->next;
        }
    }

    // check is palindrom?
    for(int i = 0; i < half; ++i)
    {
        if(first_start->val != second_start->val)
            return false;
        
        first_start = first_start->next;
        second_start = second_start->next;
    }

    return true;
}


int main()
{
    ListNode node3 = {10, NULL};
    ListNode node2 = {1, &node3};
    ListNode node1 = {1, &node2};

    printf("%d\n", (int)isPalindrome(&node1));

    return 0;
}
