class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if (!pHead)
            return NULL;
        ListNode* less = new ListNode(0);
        ListNode* less_head = less;
        ListNode* large = new ListNode(0);
        ListNode* large_head = large;
        while(pHead) {
            if (pHead->val < x) {
                less->next = pHead;
                pHead = pHead->next;
                less = less->next;
            } else {
                large->next = pHead;
                pHead = pHead->next;
                large = large->next;
            }
        }
        large->next = NULL;
        less->next = large_head->next;
        return less_head->next;
    }
};
