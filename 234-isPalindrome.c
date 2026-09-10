/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//将链表分为两个部分
//反转链表
struct ListNode* reverseList(struct ListNode* head){
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while(cur != NULL){
        struct ListNode* nextTemp = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = nextTemp;
    }
    return prev;
}
//找到回文链表 第一个重复的元素
struct ListNode* endOfFirstHalf(struct ListNode* head){
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while((fast -> next != NULL ) && ((fast -> next) -> next != NULL)){
        fast = (fast -> next )-> next;
        slow = slow -> next;
    }
    return slow;
}

bool isPalindrome(struct ListNode* head) {
    if(head == NULL){
        return true;
    }
    // 找到前半部分节点 并 反转后半部分
    struct ListNode* firstHalfEnd = endOfFirstHalf(head);
    struct ListNode* secondHalfStart = reverseList(firstHalfEnd -> next);
    struct ListNode* p1 = head;
    struct ListNode* p2 = secondHalfStart;
    bool result = true;
    while(result && p2 != NULL){
        if(p1 -> val != p2 -> val){
            result = false;
        }
        p1 = p1 -> next;
        p2 = p2 -> next;
    }
    firstHalfEnd -> next = reverseList(secondHalfStart);
    return result;
}