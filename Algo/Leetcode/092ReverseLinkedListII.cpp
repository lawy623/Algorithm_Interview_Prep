//1.Keep the original list. Keep the (m-1)-th Node place.
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* res = new_head;
        int diff = right - left;
        while(left-->1){
            new_head = new_head->next;
            head = head->next;
        }

        while(diff-->0){
            ListNode* tmp = head->next;
            head->next = head->next->next;
            tmp->next = new_head->next;
            new_head->next = tmp;
        }
        return res->next;
    }
};

// find pre and succ, reverse l->r and reconnect
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left >= right) return head;
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* l = new_head;
        ListNode* pre = NULL;
        while(left>0){
            pre = l;
            l = l->next;
            left--;
        }
        ListNode* r = new_head;
        ListNode* succ = NULL;
        while(right>=0){
            succ = r;
            r = r->next;
            right--;
        }
        swap(r, succ);

        r->next = NULL;
        pre->next = reverseList(l);
        while(l->next) l = l->next;
        l->next = succ;
        return new_head->next;
    }

    ListNode* reverseList(ListNode* cur) {
        ListNode* pre = NULL;
        ListNode* tmp;

        while(cur){
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};