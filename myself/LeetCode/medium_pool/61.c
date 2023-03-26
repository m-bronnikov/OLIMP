struct ListNode {
    int val;
    struct  ListNode *next;
};

typedef struct ListNode ListNode;

ListNode* rotateRight(ListNode* head, int k){
    if(!head) {
        return head;
    }

    ListNode* node = head;

    int size = 1;
    while(node->next) {
        ++size;
        node = node->next;
    }

    // make a circle
    node->next = head;

    // k + size rotations equal to k rotations
    k %= size;

    int last_pos = size - k - 1;
    
    node = head;
    while(last_pos--) {
        node = node->next;
    }
    
    // break circle
    head = node->next;
    node->next = 0;

    return head;
}

int main() 
{
    // this task without test
    return 0;
}