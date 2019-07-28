//1. recursion
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1 && !pHead2)
            return NULL;
        else if(!pHead1 || !pHead2)
            return !pHead1? pHead2:pHead1;

        ListNode* res = NULL;
        if (pHead1->val <= pHead2->val){
            res = pHead1;
            pHead1 = pHead1->next;
        } else {
            res = pHead2;
            pHead2 = pHead2->next;
        }
        res -> next = Merge(pHead1, pHead2);


        return res;
    }
};

//2. Loop
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (!pHead1 && !pHead2)
            return NULL;
        else if(!pHead1 || !pHead2)
            return !pHead1? pHead2:pHead1;

        ListNode* res = NULL;
        ListNode* cur = NULL;
        if (pHead1->val <= pHead2->val){
            res = pHead1;
            pHead1 = pHead1->next;
        } else {
            res = pHead2;
            pHead2 = pHead2->next;
        }

        cur = res;

        while (pHead1 || pHead2) {
            if (!pHead1) {
                cur->next = pHead2;
                break;
            }

            if (!pHead2) {
                cur->next = pHead1;
                break;
            }

            if (pHead1->val <= pHead2->val) {
                cur->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                cur->next = pHead2;
                pHead2 = pHead2->next;
            }
            cur = cur->next;
        }

        return res;
    }
};
