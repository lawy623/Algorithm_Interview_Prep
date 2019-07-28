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