//1.Keep the original list. Keep the (m-1)-th Node place.
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* mNode = new ListNode(0);
        mNode->next = head;
        ListNode* res = mNode;
        int dis = n-m;
        while(m-- > 1){
            head = head->next;
            mNode = mNode->next;
        }
        while(dis-- >0){
            ListNode *temp = head -> next;
            head -> next = head -> next -> next;
            temp -> next = mNode->next;
            mNode-> next = temp;
        }
        
        return res->next;
    }
};