// O(n) space. Use stack
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> s;
        ListNode* move = head;
        while(move) {s.push(move->val); move = move->next;}

        move = head;
        while(!s.empty()){
            if(s.top() != move->val) return false;
            else{
                s.pop();
                move = move->next;
            }
        }
        return true;
    }
};


// O(1) space with two pointer. reverse later half list
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;

        ListNode* dump = new ListNode(0);
        dump -> next = head;
        ListNode* slow = dump;
        ListNode* fast = dump;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* tmp = slow->next;
        slow->next = NULL;
        slow = head;

        tmp = reverseLL(tmp);
        fast = tmp;

        while(slow && fast){
            if (slow->val != fast->val) return false;
            else{
                slow = slow->next;
                fast = fast->next;
            }
        }
        return true;
    }

    ListNode* reverseLL(ListNode* head){
        if(!head) return NULL;

        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* tmp = NULL;
        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};