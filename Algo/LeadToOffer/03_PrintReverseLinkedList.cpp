// 1. Use stack to store the result.
// O(n) time. O(n) space.
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        while(head) {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// 2. reverse Linked list.
// O(n) time. O(1) space. But change input.
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if(head == NULL)
            return res;
        ListNode* first_node = head;
        while(head->next) {
            ListNode* temp = head->next;
            head->next = head->next->next;
            temp->next = first_node;
            first_node = temp;
        }
        while(first_node){
            res.push_back(first_node->val);
            first_node = first_node->next;
        }
        return res;
    }
};
