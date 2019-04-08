//1. Keep a pre pointer for the last not equal num. Last -> head will be the whole equal 
//list.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode top(-1);
        top.next = head;
        ListNode* last = head;
        ListNode* pre = &top;
        if(!head) return head;
        head = head ->next;
        bool remove = false;
        while(head){
            if(head -> val == last -> val){
                head = head -> next;
                remove = true;
            }
            else{
                while(last->val!=head->val){
                    last = last -> next;
                }
                if(remove){
                    pre -> next = head;
                }
                else{
                    pre = pre -> next;
                }
                head = head->next; 
                remove = false;
            }
        }
        if(remove)
            pre -> next = NULL;
        return top.next;
    }
};

//2. Easy Recursion.
class Solution {
    public:
        ListNode *deleteDuplicates(ListNode *head) {
        if (!head || !head->next) return head;
        ListNode *p = head->next;
        if (head->val == p->val) {
            while (p && head->val == p->val) {
            p = p->next;
        }
            return deleteDuplicates(p);
        } else {
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};