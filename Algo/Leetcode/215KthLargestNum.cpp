class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(k<=0 || k>nums.size()) return -1;

        int start = 0; int end = nums.size()-1;
        int p = partition(nums, start, end);
        while(p != k-1){
            if (p>k-1)
                end = p-1;
            else
                start = p+1;
            p = partition(nums, start, end);
        }
        return nums[p];
    }

    int partition(vector<int>& nums, int start, int end){
        if(end<=start) return start;
        int pivot_idx = rand() % (end - start + 1) + start;
        swap(nums[pivot_idx], nums[end]);
        int idx = start - 1;
        for(int i=start; i<end; i++){
            if(nums[i] >= nums[end])
                swap(nums[++idx], nums[i]);
        }
        swap(nums[++idx], nums[end]);
        return idx;
    }
};