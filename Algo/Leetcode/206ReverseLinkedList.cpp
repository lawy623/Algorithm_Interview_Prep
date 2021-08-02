//1. Keep the head on the first one. Move the afterwards one to the front one by one. O(n).
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* res = head;
        while(head->next!=NULL){
            ListNode* temp = head->next;
            head->next = head->next->next;
            temp -> next = res;  //Make to the first place.
            res = temp;
        }
        return res;
    }
};

// pre cur two pointer. easy to understand
class Solution {
public:
    ListNode* reverseList(ListNode* cur) {
        ListNode* pre = NULL;
        ListNode* tmp;

        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};