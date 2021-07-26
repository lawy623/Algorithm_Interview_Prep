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
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int kth = findK(arr, k-1);
        vector<int> res;
        for(auto n : arr){
            if (n<=kth && res.size()<k)
                res.push_back(n);
        }
        return res;
    }

    int findK(vector<int>& arr, int k){
        if (k<0 || k>arr.size()-1) return -1;
        int start = 0; int end = arr.size()-1;

        int p = partition(arr, start, end);
        while(p!=k){
            if(p>k) end = p-1;
            else start = p+1;
            p = partition(arr, start, end);
        }
        return arr[p];
    }

    int partition(vector<int>& arr, int start, int end){
        if(end<=start) return start;
        int pivot_idx = rand() % (end - start + 1) + start;
        swap(arr[pivot_idx], arr[end]);
        int idx = start-1;
        for(int i=start; i<end; i++){
            if(arr[i] <= arr[end])
                swap(arr[++idx], arr[i]);
        }
        swap(arr[++idx], arr[end]);
        return idx;
    }
};
