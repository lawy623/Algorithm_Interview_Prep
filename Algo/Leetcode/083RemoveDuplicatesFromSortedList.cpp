//Use two pointer. Prev pointer update to cur if finally go out the equal ones.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* move = head;
        while(move->next){
            if(move->next->val == move->val){
                move->next = move->next->next;
            } else move=move->next;
        }
        return head;
    }
};