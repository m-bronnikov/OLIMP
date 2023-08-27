#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
 
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur = head;

    while(cur) {
        int cur_value = cur->val;

        ListNode* next = cur->next;
        while(next && next->val == cur_value) {
            next = next->next;
        }

        cur->next = next;
        cur = next;
    }

    return head;
}

int main() {
    // There is solution without test cases
    return 0;
}