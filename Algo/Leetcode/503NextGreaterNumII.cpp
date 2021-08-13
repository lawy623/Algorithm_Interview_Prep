// dict + 单调栈
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;

        vector<int> res(n, -1);
        for(int i=0; i<nums.size()*2-1; i++){
            while(!s.empty() && nums[s.top() % n] < nums[i % n]){
                res[s.top() % n] = nums[i % n];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};