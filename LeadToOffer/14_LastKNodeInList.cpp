// cpp. two pointer. O(n) time.
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (k==0)
            return NULL;

        ListNode* head = pListHead;
        while (k>0){
            if (!head)
                return NULL;
            k--;
            head = head -> next;
        }

        ListNode* tail = pListHead;
        while (head) {
            head = head -> next;
            tail = tail -> next;
        }
        return tail;
    }
};
