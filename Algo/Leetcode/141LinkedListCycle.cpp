//1. Use a fast pointer and a slow pointer. If they meet. It has cycle. O(N).
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) return true;
        }
        return false;
    }
};