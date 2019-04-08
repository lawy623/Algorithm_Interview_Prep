//1. Keep top/prev/cur pointer for a fixed place. h pointer to loop over top ->pre to compare with h.
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* cur = head;
        ListNode a(-1);
        ListNode* h = &a;
        h->next = head;
        ListNode* top = h, *prev = h;
        int n = 0;
        int needStep = 0;
        while(cur){
            if(n==0) {cur = cur->next; prev = prev->next; needStep++; n=needStep; h = top;} //If we can not find.
            else{
                if(cur -> val >= h ->next -> val) {n--;h = h->next;}
                else{
                    prev -> next = cur -> next;
                    cur-> next = h -> next;
                    h -> next = cur;
                    cur = prev -> next;
                    needStep++; n=needStep; h = top;
                }
            }
        }
        return top->next;
    }
};


//Consice Version.
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *cur = head;
        while (cur) {
            if ((cur -> next) && (cur -> next -> val < cur -> val)) {
                while (pre -> next -> val < cur -> next -> val) {
                    pre = pre -> next;
                }
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
              
                pre = dummy;
                //cur = cur->next;
            }
            else {
                cur = cur -> next;
            }
        }
        return dummy -> next;
    }
};