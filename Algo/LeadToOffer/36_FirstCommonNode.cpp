//1. Use map. O(m+n) time. O(n) space.
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2)
            return NULL;
        unordered_map<ListNode*, int> map;
        while(pHead1) {
            map[pHead1] = 0;
            pHead1 = pHead1->next;
        }
        while(pHead2) {
            if (map.find(pHead2)!=map.end())
                return pHead2;
            pHead2 = pHead2->next;
        }
        return NULL;
    }
};

//2. The part after common are the same. Let the fast go by diff, then compare the two list with same length.
//O(n) time, O(1) space.
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if (!pHead1 || !pHead2)
            return NULL;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        int len1 = 0, len2 = 0;
        while(p1) {
            len1++;
            p1 = p1->next;
        }
        while(p2){
            len2++;
            p2 = p2->next;
        }
        p1 = pHead1;
        p2 = pHead2;
        if (len1>len2) {
            while(len1-- >len2)
                p1 = p1->next;
        } else if (len1<len2){
            while(len2-- >len1)
                p2 = p2->next;
        }
        while(p1){
            if (p1==p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};

// 交叉遍历
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;

        ListNode* A = headA;
        ListNode* B = headB;
        while(A || B){
            if(A == B) break;
            A = A?A->next:headB;
            B = B?B->next:headA;
        }
        return A;
    }
};