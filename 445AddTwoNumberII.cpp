//1.Use stack to reverse the linkedlists. Then Pop and add up.   36ms
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        while(l1){
            st1.push(l1->val);
            l1 = l1 -> next;
        }
        while(l2){
            st2.push(l2->val);
            l2 = l2 -> next;
        }
        
        ListNode *head = nullptr;
        int sum = 0, carry=0;
        while(!st1.empty() || !st2.empty() || carry){
            int a=0,b =0;
            if(!st1.empty()){
                a = st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                b = st2.top();
                st2.pop();
            }
            sum = a + b + carry;
            carry = sum / 10;
            ListNode* newNode = new ListNode(sum%10);
            newNode->next = head;    //newnode指向现有的list
            head = newNode;          //让head不断指向新的newnode，最后return head           
        }
        return head;
    }
};