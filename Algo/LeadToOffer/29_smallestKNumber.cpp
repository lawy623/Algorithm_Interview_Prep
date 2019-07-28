//1. Use min heap. Build on input. So O(1) space and O(n+klogn) time.
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (input.size()==0 || k<=0 || k>input.size())
            return res;

        make_heap(input.begin(), input.end(), greater<int>());

        while (k-- >0) {
            res.push_back(input.front());
            pop_heap(input.begin(), input.end());
            input.pop_back();
            sort_heap(input.begin(),input.end());
        }
        return res;
    }
};

//2. Use extra min heap. O(n) space, O(n+klogn) time.
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (input.size()==0 || k<=0 || k>input.size())
            return res;

        priority_queue<int, vector<int>, greater<int> > q(input.begin(), input.end());

        while (k-- >0) {
            res.push_back(q.top());
            q.pop();
        }
        return res;
    }
};
//3. Use partition and find the k-th smallest. Total O(n) time.
class Solution {
public:
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

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if (input.size()==0 || k<=0 || k>input.size())
            return res;

        int kth = findKSmallest(input, k);
        for(int i=0; i<input.size(); i++){
            if (input[i]<kth)
                res.push_back(input[i]);
        }
        while(res.size()<k) {
            res.push_back(kth);
        }

        return res;
    }
};
