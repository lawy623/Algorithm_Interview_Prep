//1. Use two List to store smaller ones and the bigger ones. Merge Them together at last. O(n)
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode l(-1);
        ListNode* l_p = &l;
        ListNode r(-1);
        ListNode* r_p = &r;
        
        while(head){
            if(head -> val < x){
                l_p -> next = head;
                l_p = l_p -> next;
            }
            else{
                r_p -> next = head;
                r_p = r_p -> next;
            }
            head = head -> next;
        }
        
        l_p -> next = r.next;
        r_p -> next = NULL;
        return l.next;
    }
};