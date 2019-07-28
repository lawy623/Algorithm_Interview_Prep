//1.Directly Compute. O(m+n)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* res = head;
        
        while(l1&&l2){
            if(l1->val <= l2->val){head->next = l1;head = l1; l1 = l1->next;}
            else {head->next = l2;head = l2; l2 = l2->next;}
        }
        
        //if(!l1 && !l2) head->next=NULL;
        //else if(!l1) head->next=l2;
        //else if(!l2) head->next=l1;
        //else{}
        head->next = l1 ? l1 : l2;
        
        return res->next;
    }
};

 
//2. recursion O(m+n)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {      
        if(!l1 && !l2) return NULL;
        else if(!l1) return l2;
        else if(!l2) return l1;
        else{
            if(l1->val <= l2->val) {l1->next=mergeTwoLists(l1->next,l2);return l1;}
            else {l2->next=mergeTwoLists(l1,l2->next);return l2;}
        }
    }
};