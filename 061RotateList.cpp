//1. Link the last node to the first. And record length. Move len - k and link to NULL. O(N).
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        if(!head) return head;
        ListNode* top = head;
        while(head->next){
            head = head -> next;
            len ++;
        }
        len ++;
        k = k % len;
        head -> next = top;
        for(int i=0;i<len-k;i++){
            head = head ->next;
        }
        ListNode* res = head -> next;
        head -> next = NULL;
        return res;
    }
};