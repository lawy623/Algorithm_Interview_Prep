//1. Keep two pointers. One is n step forward than the others. When this one reach the end, another is at the nth. O(N)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur, *pre;
        cur = head; pre = head;
        
        int i=n;
        while(i-->0) pre = pre->next;  //Question assume that the n<list.length()
        if(!pre) return head->next;
        
        while(pre->next){ //This is important. At the end pre is at last node, cur is at last (n+1) node.
            pre = pre->next;
            cur = cur->next;
        }
        cur -> next = cur -> next -> next;
        
        return head;
    }
};