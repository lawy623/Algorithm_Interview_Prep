//1. Compare the head of the k lists. Then recurrsion. Remember to consider nulls. O(kn).
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* res = nullptr;
        if(!lists[0]) {lists.erase(lists.begin());return mergeKLists(lists);}
        int minN = lists[0]->val;
        int minId = 0;
        for(int i=1;i<lists.size();i++){
            if(!lists[i]){
                continue;
            }
            if(lists[i]->val < minN){
                minN = lists[i]->val;
                minId = i;
            }
        }
      
        res = lists[minId];
        if(!lists[minId] -> next){
            lists.erase(lists.begin()+minId);
        }
        else lists[minId] = lists[minId] -> next;
        res -> next = mergeKLists(lists);
        return res;
    }
};

// 2. 两两merge。  O(nlogk).
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* res = NULL;
        int k = lists.size();
        int idx;
        while(k>1){
            idx = 0;
            for(int i=0; i<k; i+=2){
                if(i==k-1) lists[idx++] = lists[i];
                else lists[idx++] = merge2Lists(lists[i], lists[i+1]);
            }
            k = idx;
        }
        return lists[0];
    }

    ListNode* merge2Lists(ListNode* a, ListNode* b){
        if(!a && !b) return NULL;
        if(!a) return b;
        if(!b) return a;

        ListNode* res;
        if(a->val < b->val){
            res = a;
            a = a->next;
        } else{
            res = b;
            b = b->next;
        }
        res -> next = merge2Lists(a, b);
        return res;
    }
};