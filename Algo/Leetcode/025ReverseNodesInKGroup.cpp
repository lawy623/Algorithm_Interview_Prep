//1. Write a full reverse function first. Reverse each group. Make the last recursion.
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* res = head, *first = head;
        int count = k;
        if(!head) return head;
        while( count >1 && head-> next){
            cout<< head -> val<< endl;
            head = head -> next;
            count--;
        }
        if(count>1) return res;
        else{
            ListNode* temp = head -> next;
            head -> next = NULL;
            res = reverseList(res);
            first -> next = reverseKGroup(temp,k);
        }
        return res;        
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        ListNode* res = head;
        while(head->next){
            ListNode* temp = head->next;
            head->next = temp->next;
            temp -> next = res;
            res = temp;
        }
        return res;
    }     
};

// 2. directly reverse k nodes and recursive
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        if(k<=1) return head;
        int k1 = k-1;
        ListNode* move = head;
        while(k1>0 && move){
            move = move->next;
            k1--;
        }
        if(!move) return head;
        ListNode* new_head = new ListNode(0);
        new_head->next = head;
        ListNode* succ = move->next;
        ListNode* tmp = NULL;
        while(head->next != move){          // reverse from head to move's pre
            tmp = head->next;
            head->next = head->next->next;
            tmp->next = new_head->next;
            new_head->next = tmp;
        }

        move->next = new_head->next;     // move moveNode to begin, recursively remove later
        new_head->next = move;
        head->next = reverseKGroup(succ, k);
        return new_head->next;
    }
};