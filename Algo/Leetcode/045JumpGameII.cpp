// greedy. Always find the rightmost reachable boarder.
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return true;
        int step = 0;
        int right = 0;
        int end = 0;
        for(int i=0; i<nums.size()-1; i++){
            right = max(right, i+nums[i]);
            if(i == end){
                end = right;
                step++;
            }
        }
        return step;
    }
};