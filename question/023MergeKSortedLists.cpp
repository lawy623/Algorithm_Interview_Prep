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