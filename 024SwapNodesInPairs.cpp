//1. Easy exchange on pairs.
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode top(-1);
        ListNode* prev = &top;
        ListNode* cur = head;
        top.next = head;
        
        while(cur && cur -> next){
            ListNode* tmp = cur->next;
            prev -> next = cur -> next;
            cur -> next = cur -> next -> next;
            tmp -> next = cur;
            
            cur = cur -> next;
            prev = prev -> next -> next;
        }
        return top.next;
    }
};