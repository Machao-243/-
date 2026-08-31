/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* fhead = malloc(sizeof(struct ListNode));
    fhead -> next = head;
    struct ListNode* temp = fhead;
    while(temp -> next != NULL){
        if(temp -> next -> val == val){
            temp -> next = temp -> next -> next;
        }else{
            temp = temp -> next;
        }
    }
    return fhead -> next;
}