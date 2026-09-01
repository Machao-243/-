struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* pre = NULL;
    struct ListNode* cur = head;
    while(cur){
        struct ListNode* nxt = cur->next;
        cur -> next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}