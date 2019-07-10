bool checkMoreThanHalf(int res, vector<int> numbers) {
    int count = 0;
    for (int i=0; i<numbers.size(); i++) {
        if (numbers[i]==res)
            count ++;
    }
    if (count>numbers.size()/2)
        return true;
    return false;
}
//1. use heap. Build heap is O(n), but pop takes O(nlogn). Need to check whether the number really over half.
int MoreThanHalfNum_Solution(vector<int> numbers) { // use heap
    vector<int> nums(numbers.begin(), numbers.end());

    make_heap(nums.begin(), nums.end());
    int len = (nums.size()-1) / 2;
    while (len-- >0) {
        pop_heap(nums.begin(), nums.end());
        nums.pop_back();
    }

    int res = nums.front();

    if (checkMoreThanHalf(res, numbers))
        return res;
    return 0;
}
int MoreThanHalfNum_Solution(vector<int> numbers) { // use priority_queue
    priority_queue<int> nums(numbers.begin(), numbers.end());

    int len = (nums.size()-1) / 2;
    while (len-- >0) {
        nums.pop();
    }

    int res = nums.top();

    if (checkMoreThanHalf(res, numbers))
        return res;
    return 0;
}
//2. Use partition. Find the k-th value.
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int pos = left-1;
        for (int i=left; i<right; i++) {
            if (nums[i] <= pivot) {
                swap(nums[++pos], nums[i]);
            }
        }
        swap(nums[++pos], nums[right]);
        return pos;
    }

    int findKSmallest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size()-1;
        int idx = 0;
        while(true) {
            idx = partition(nums, left, right);
            if (idx==k-1)
                return nums[idx];
            else if (idx>k-1)
                right = idx - 1;
            else
                left = idx + 1;
        }
    }

    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.size()==0)
            return 0;
        int half = numbers.size()/2;

        int res = findKSmallest(numbers, half);
        if (checkMoreThanHalf(res, numbers))
            return res;
        return 0;
    }
