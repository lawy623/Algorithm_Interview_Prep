class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* slow = pHead, * fast = pHead;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            slow = slow -> next;

            if(fast == slow){
                ListNode* slow2 =pHead;
                while(slow2 != slow){
                    slow2 = slow2->next;
                    slow = slow->next;
                }
                return slow2;
            }
        }
        return NULL;
    }
};

//Suppose the entrance of loop needs (a) steps to reach. Suppose loop is r steps.
//Suppose the slow one use k steps to meet fast. Then fast move 2k steps.
// We have   slow one use (a+t) steps to meet fast.
//k=a+t && 2k=a+nr+t. ->> nr = k = a+t.
//(n-1)r + r = a+t.  -> a = r-t + (n-1)r.
//If we use a slow2 pointer to go when slow&fast meet. We need (a) steps to the entrances. Slow one can go (r-t) + (n-1)r which will also get to the entrance. When they meet. return the entrance.
