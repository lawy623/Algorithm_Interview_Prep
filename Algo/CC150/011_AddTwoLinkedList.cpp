// 1.
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        if (!a && !b)    return NULL;
        if (!a)    return b;
        if (!b)    return a;
        ListNode* res = new ListNode(-1);
        ListNode* res_head = res;
        int carry = 0;
        while(a || b || carry) {
            int a_v = a?a->val:0;
            int b_v = b?b->val:0;
            int sum = a_v + b_v + carry;
            carry = sum / 10;
            sum = sum % 10;
            res->next = new ListNode(sum);
            a = a?a->next:a;
            b = b?b->next:b;
            res = res->next;
        }
        return res_head->next;
    }
};

// 2. origin. Too long
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
        if (!a && !b)    return NULL;
        if (!a)    return b;
        if (!b)    return a;
        ListNode* res = new ListNode(-1);
        ListNode* res_head = res;
        int carry = 0;
        while(a && b) {
            int sum = a->val + b->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            res->next = new ListNode(sum);
            a = a->next;
            b = b->next;
            res = res->next;
        }
        if (!a && !b && carry){
            res -> next = new ListNode(carry);
            carry = carry / 10;
            res = res->next;
        } else if(!a) {
            while(b) {
                int sum = b->val + carry;
                carry = carry / 10;
                sum = sum % 10;
                res ->next = new ListNode(sum);
                res = res->next;
                b = b->next;
            }
        } else if (!b) {
            while(a) {
                int sum = a->val + carry;
                carry = carry / 10;
                sum = sum % 10;
                res ->next = new ListNode(sum);
                res = res->next;
                a = a->next;
            }
        }
        if (carry) {
            res ->next = new ListNode(carry);
        }
        return res_head->next;
    }
};
