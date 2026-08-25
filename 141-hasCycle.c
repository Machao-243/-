/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head -> next == NULL){
        return false;
    }
    struct ListNode* fast = head -> next;
    struct ListNode* slow = head;
    while(slow != fast){
        if(fast == NULL || fast -> next == NULL){
            return false;
        }
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return true;
}