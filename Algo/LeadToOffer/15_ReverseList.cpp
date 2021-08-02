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


// pre cur two pointer. easy to understand
class Solution {
public:
    ListNode* reverseList(ListNode* cur) {
        ListNode* pre = NULL;
        ListNode* tmp;

        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};
