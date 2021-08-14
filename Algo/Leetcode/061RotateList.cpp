//1. Link the last node to the first. And record length. Move len - k and link to NULL. O(N).
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head) return head;
        ListNode* fast = head;
        int count = 1;
        while(fast->next){
            fast = fast->next;
            count++;
        }
        fast->next = head; // make it circle

        k = k % count;
        fast = head;
        for(int i=0; i<count-k-1; i++) fast = fast->next;

        ListNode* new_head = fast->next;
        fast->next = NULL;
        return new_head;
    }
};