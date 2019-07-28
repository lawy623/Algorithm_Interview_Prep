// O(1) time.
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (!pHead)
            return NULL;

        ListNode* pFirst = pHead;
        ListNode* temp = NULL;
        while (pHead->next) {
            temp = pHead->next;
            pHead->next = temp->next;
            temp->next = pFirst;
            pFirst = temp;
        }
        return pFirst;
    }
};
