//1. Write a full reverse function first. Reverse each group. Make the last recursion.
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = head, *first = head;
        int count = k;
        if(!head) return head;
        while( count >1 && head-> next){
            cout<< head -> val<< endl;
            head = head -> next;
            count--;
        }
        if(count>1) return res;
        else{
            ListNode* temp = head -> next;
            head -> next = NULL;
            res = reverseList(res);
            first -> next = reverseKGroup(temp,k);
        }
        return res;        
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* res = head;
        while(head->next){
            ListNode* temp = head->next;
            head->next = temp->next;
            temp -> next = res;
            res = temp;
        }
        return res;
    }     
};