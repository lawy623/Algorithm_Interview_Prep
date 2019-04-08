//1. Use merge sort. O(NlgN).
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow = head, *fast = head, *prev = head;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast -> next -> next;
        }
        prev -> next = NULL;
        return mergeSortedLists(sortList(head),sortList(slow));
    }
    
    ListNode* mergeSortedLists(ListNode* l1, ListNode*l2){
        if(!l1 && !l2) return NULL;
        else if(!l1) return l2;
        else if(!l2) return l1;
        else{
            if(l1->val < l2->val) {l1->next = mergeSortedLists(l1->next,l2);return l1;}
            else{l2->next = mergeSortedLists(l1,l2->next);return l2;}
        }
    }
};