// stack. O(n) space and time
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        stack<int> s;
        int left = n;
        for(int i=0; i<n; i++){
            while(!s.empty() && nums[s.top()] > nums[i]){
                left = min(left, s.top());   // the left-most item that nums[i] > nums[i+k], you need to move nums[i] away
                s.pop();
            }
            s.push(i);
        }

        int right = -1;
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && nums[s.top()] < nums[i]){
                right = max(right, s.top());  // the right-most item that nums[i] < nums[i-k], you need to move nums[i] away
                s.pop();
            }
            s.push(i);
        }

        return right>left?right-left+1:0;
    }
};

// O(1) space with two pointer
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int l=0; int r=0;
        int n = nums.size();

        int max = 0;
        for(int i=1; i<n; i++){
            if(nums[i] >= nums[max]) max = i;
            else r = i;
        }

        int min = n-1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] <= nums[min]) min = i;
            else l = i;
        }

        return r>l?r-l+1:0;
    }
};