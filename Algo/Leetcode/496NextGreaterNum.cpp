// dict + 单调栈
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        map<int, int> d;
        for(int i:nums2) d[i] = -1;

        stack<int> s;
        for(int i=0; i<m; i++){
             while(!s.empty() && nums2[s.top()] < nums2[i]){
                 d[nums2[s.top()]] = nums2[i];
                 s.pop();
             }
             s.push(i);
        }

        vector<int> res;
        for(int i:nums1){
            if(d[i]==-1) res.push_back(-1);
            else res.push_back(d[i]);
        }
        return res;
    }
};