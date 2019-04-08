//1.Directly loop over the two linked lists. Take care of null pointers.
class Solution { //28ms. 都用pointer更快一点
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);    //This point will move towards the end.
        ListNode* res = head;     //For here, keep the unmoved pointer to output result.
        
        int carry =0;
        while(l1 || l2 || carry){  //This comparison is good.
            int a = l1? l1->val : 0;
            int b = l2? l2->val : 0;
            head->next = new ListNode((a+b+carry)%10);  //Keep moving the head pointer.
            carry = (a+b+carry) / 10;
            l1 = l1? l1->next : nullptr;   //If set to null, will change the next a/b to be 0;
            l2 = l2? l2->next : nullptr;
            head = head->next;          
        }
        return res->next;
    }    
};

class Solution { //32ms.创建多一个head的instance耗费时间
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0); //= new ListNode(0);    //This point will move towards the end.
        ListNode* res = &head;     //For here, keep the unmoved pointer to output result.
        
        int carry =0;
        while(l1 || l2 || carry){  //This comparison is good.
            int a = l1? l1->val : 0;
            int b = l2? l2->val : 0;
            res->next = new ListNode((a+b+carry)%10);  //Keep moving the head pointer.
            carry = (a+b+carry) / 10;
            l1 = l1? l1->next : nullptr;   //If set to null, will change the next a/b to be 0;
            l2 = l2? l2->next : nullptr;
            res = res->next;          
        }
        return head.next;

    }    
};

//2.递归recurrsion。主要为了可以控制carry的值作为输入，将整个l1作为输出。 64ms
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1, l2, 0);
    }
    
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry) {
        if(l1 == NULL)
            return addTwoNumbers(l2, carry);
        if(l2 == NULL)
            return addTwoNumbers(l1, carry);
        l1->val += (l2->val + carry);
        l1->next = addTwoNumbers(l1->next, l2->next, l1->val / 10); //这一步关键。递归精髓，将l1的next继续递归输出。最后输出l1
        l1->val %= 10;
        return l1;
    }
    
    ListNode *addTwoNumbers(ListNode *l, int carry) {
        if(l == NULL)
            if (carry)
                return new ListNode(carry);
            else
                return NULL;
        l->val += carry;
        l->next = addTwoNumbers(l->next, l->val / 10);
        l->val %= 10;
        return l;

    }
};

//简化递归 28ms
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbers(l1, l2, 0);
    }
  
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2,int carry){
        ListNode* l = new ListNode(0);
        if(l1!=NULL || l2!=NULL || carry){
            int a = l1? l1->val : 0;
            int b = l2? l2->val : 0;
            l1 = l1? l1->next : NULL;
            l2 = l2? l2->next : NULL;
            int sum = a + b + carry; 
            l->val = sum % 10;
            l->next = addTwoNumbers(l1,l2,sum/10);
            return l;
        }else
            return NULL;
    }
};