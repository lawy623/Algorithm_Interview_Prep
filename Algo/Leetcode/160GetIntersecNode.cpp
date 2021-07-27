class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        int m = 0; int n = 0;
        ListNode* move = headA;
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        while(move){
            m++;
            move = move->next;
        }
        move = headB;
        while(move){
            n++;
            move = move->next;
        }
        if(m>n){
            while(m>n){
                p1 = p1->next;
                m--;
            }
        } else if (m<n){
            while(m<n){
                p2 = p2->next;
                n--;
            }
        }
        while(p1 && p2){
            if(p1 == p2)
                return p1;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        return NULL;
    }
};