//1. Easy exchange on pairs.
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* new_head = new ListNode(-1);
        new_head -> next = head;
        ListNode* move = new_head;
        while(head && head->next){
            move->next = head->next;
            head->next = move->next->next;
            move->next->next = head;
            move = move->next->next;
            head = head->next;
        }
        return new_head->next;
    }
};