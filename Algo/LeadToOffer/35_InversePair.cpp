// 1. BF. O(n^2) time.
class Solution {
public:
    int InversePairs(vector<int> data) {
        if (data.size()==0)
            return 0;
        int count = 0;
        for (int i=0; i<data.size()-1; i++) {
            for (int j=i+1; j<data.size(); j++) {
                if (data[i]>data[j])
                    count ++;
            }
        }
        return count%10000000007;
    }
};

// 2. Merge and count. O(nlogn) time and O(n) space.
int MergeAndCount(vector<int>& data, int start, int end) {
    if (start==end)
        return 0;
    if (start==end-1) {
        if (data[start]<=data[end])
            return 0;
        else {
            swap(data[start], data[end]);
            return 1;
        }
    }
    int mid = (start+end)/2;
    long long count_l = MergeAndCount(data, start, mid);
    long long count_r = MergeAndCount(data, mid+1, end);
    int p1 = 0, p2 = 0;
    long long count = 0;
    vector<int> l;
    vector<int> r;

    for(int i = start; i<=mid; i++)
        l.push_back(data[i]);
    for(int i = mid+1; i<=end; i++)
        r.push_back(data[i]);
    for(int i = start; i<=end; i++) {
        if(p2==r.size()){
            data[i] = l[p1++];
            count += p2;
        } else if (p1==l.size()) {
            data[i] = r[p2++];
        } else if (l[p1]<=r[p2]) {
            data[i] = l[p1++];
            count += p2;
        }
        else if (l[p1]>r[p2]) {
            data[i] = r[p2++];
        }
    }

    return count + count_l + count_r;
}
int InversePairs(vector<int> data) {
    if (data.size()==0)
        return 0;
    long long count = MergeAndCount(data, 0, data.size()-1);
    return count%1000000007;
}

// Use one tmp vector to store
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        long long count = 0;
        if(nums.size()==0) return 0;
        vector<int> tmp(nums.size());
        return mergeCount(nums, 0, nums.size()-1, tmp);
    }

    int mergeCount(vector<int>& nums, int start, int end, vector<int>& tmp){
        if(start>=end) return 0;
        if(start == end - 1){
            if(nums[start] <= nums[end]) return 0;
            swap(nums[start], nums[end]);
            return 1;
        }
        int m = (start + end) / 2;
        long long count = mergeCount(nums, start, m-1, tmp) + mergeCount(nums, m, end, tmp);
        int l1 = start; int l2 = m;
        for(int i=start; i<=end; i++){
            if(l2 == end+1){
                count += (end - m + 1);
                tmp[i] = nums[l1++];
            }
            else if(l1 == m){
                tmp[i] = nums[l2++];
            } else if(nums[l1] <= nums[l2]){
                count += (l2 - m);
                tmp[i] = nums[l1++];
            } else {
                tmp[i] = nums[l2++];
            }
        }
        for(int i=start; i<=end; i++) nums[i] = tmp[i];
        return count;
    }
};