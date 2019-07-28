//1. Break down at the middle. Reverse the later one. Then merge.
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow = head, *fast = head, * pre = slow;
        while(fast && fast -> next){ //Use slow to find the middle. 
            pre = slow;               //Slow always in last half.
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        pre -> next = nullptr; //Break the list.
        slow = reverse(slow);   //Use reverse to reverse the whole list.
        ListNode* cur = head;
        while(cur->next){
            ListNode* temp = cur -> next;
            cur -> next = slow;
            slow = slow -> next;
            cur -> next -> next = temp;
            cur = temp;
        }
        cur -> next = slow;  //The slow list is not less than cur list.
    }
    
    ListNode* reverse(ListNode* head){
        if(!head) return head;
        ListNode* res = head;
        while(head->next){
            ListNode* temp = head->next;
            head -> next = head ->next->next;
            temp -> next =res;
            res = temp;
        }
        return res;
    }
};