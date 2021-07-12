// 1. Use QuickSort(O(NlogN)). Remember to use random pivot rather than always the last one.
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sortArray(nums, 0, nums.size()-1);
        return nums;
    }

    void sortArray(vector<int>& nums, int start, int end){
        if (start < end){
            int p = random_partition(nums, start, end);
            sortArray(nums, start, p-1);
            sortArray(nums, p+1, end);
        }
    }

    int random_partition(vector<int>& nums, int start, int end){
        int pivot = rand() % (end - start + 1) + start;
        swap(nums[pivot], nums[end]);
        int p = partition(nums, start, end);
        return p;
    }

    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[end];
        int move = start - 1;
        for(int i=start; i<end; i++){
            if (nums[i] <= pivot)
                swap(nums[++move], nums[i]);
        }
        swap(nums[++move], nums[end]);
        return move;
    }
};