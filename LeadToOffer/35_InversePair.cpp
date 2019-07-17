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
