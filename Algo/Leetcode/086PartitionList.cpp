//1. Use two List to store smaller ones and the bigger ones. Merge Them together at last. O(n)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        ListNode* l = new ListNode(0);
        ListNode* r = new ListNode(0);
        ListNode* l_move = l;
        ListNode* r_move = r;
        while(head){
            if(head->val < x){
                l_move -> next = head;
                l_move = l_move -> next;
            } else{
                r_move->next = head;
                r_move = r_move -> next;
            }
            head = head->next;
        }
        l_move -> next = r->next;
        r_move -> next = NULL;
        return l -> next;
    }
};