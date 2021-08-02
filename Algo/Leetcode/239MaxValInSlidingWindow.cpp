class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> res;
        if(nums.size()==0 || k ==0) return res;
        for(int i=0; i<nums.size(); i++){
            while(!window.empty() && window.front() <= i-k)
                window.pop_front();
            while(!window.empty() && nums[window.back()] < nums[i])
                window.pop_back();
            window.push_back(i);
            if(i>=k-1) res.push_back(nums[window.front()]);
        }

        return res;
    }
};