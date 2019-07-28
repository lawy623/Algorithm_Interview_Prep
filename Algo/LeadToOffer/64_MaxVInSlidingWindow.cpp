// 1. brute force, but dp also. O(nk) time.
class Solution {
public:
    int max_size(vector<int> num, int start, int size) {
        int max_v = INT_MIN;
        for(int i=0;i<size;i++)
            max_v = max_v>num[start+i]?max_v:num[start+i];
        return max_v;
    }
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if (size==0 || num.size()==0 || size>num.size())
            return res;
        int sum = max_size(num, 0, size);
        res.push_back(sum);
        for (int i=1; i<=num.size()-size; i++) {
            if (res[i-1]>num[i-1])
                res.push_back( num[i+size-1]>res[i-1]?num[i+size-1]:res[i-1] );
            else
                res.push_back( max_size(num, i, size) );
        }
        return res;
    }
};

// 2. Use a deque. O(n) time.
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& a, unsigned int k){
        vector<int> res;
        if (k==0)
            return res;
        deque<int> s;
        for(unsigned int i = 0; i < a.size(); ++i){
            // smaller values can not be the max in windows
            while(s.size() && a[s.back()] <= a[i]) s.pop_back();
            // remove out of range previous value
            while(s.size() && s.front() + k - 1 <i) s.pop_front();
            s.push_back(i);
            // only after first few insertions.
            if(i >= k-1) res.push_back(a[s.front()]);
        }
        return res;
    }
};
