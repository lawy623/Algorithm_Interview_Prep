//Use two pointer. Prev pointer update to cur if finally go out the equal ones.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* prev = head, *cur = head->next;
        while(cur){
            if(cur->val == prev->val){
                prev->next = cur->next;
            }
            else{
                prev = cur;
            }
            cur = cur -> next;   
        }
        return head;
    }
};