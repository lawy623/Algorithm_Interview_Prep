// 1. Use stack. O(n) space, O(n) time
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        if (!pHead)
            return true;
        stack<int> s;
        ListNode* move = pHead;
        while(move) {
            s.push(move->val);
            move = move->next;
        }
        while(pHead) {
            if (pHead->val != s.top())
                return false;
            pHead = pHead->next;
            s.pop();
        }
        return true;
    }
};

// 2. Use fast+slow pointers. Reduce stack by half.
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        if (!pHead)
            return true;
        stack<int> s;
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while(fast && fast->next) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast)
            slow = slow->next;
        while(slow) {
            if (slow->val != s.top())
                return false;
            slow = slow->next;
            s.pop();
        }
        return true;
    }
};
