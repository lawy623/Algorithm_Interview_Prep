//1. Recursion.
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (!pHead)
            return NULL;
        if (!pHead->next)
            return pHead;
        ListNode* res = pHead;
        if (pHead->val == pHead->next->val) {
            int v = pHead->val;
            while(pHead && pHead->val == v) {
                pHead = pHead->next;
            }
            res = deleteDuplication(pHead);
        } else {
            pHead = pHead->next;
            res -> next = deleteDuplication(pHead);
        }
        return res;
    }
};
