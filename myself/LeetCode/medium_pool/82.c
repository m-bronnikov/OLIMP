#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
 
ListNode* deleteDuplicates(ListNode* head) {
    ListNode fake = {0, head};

    ListNode* prev = &fake;
    ListNode* cur = head;

    while(cur) {
        int cur_value = cur->val;
        int cur_value_count = 0;

        while(cur && cur->val == cur_value) {
            cur = cur->next;
            ++cur_value_count;
        }

        if(cur_value_count > 1) {
            prev->next = cur;
        } else {
            prev = prev->next;
        }
    }

    return fake.next;
}

int main() {
    // There is solution without test cases
    return 0;
}