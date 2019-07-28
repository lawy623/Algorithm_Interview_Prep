//1. binary count. O(logn) time.
class Solution {
public:
    int binaryCount(vector<int> data, int k, int start, int end) {
        if (start>end)
            return 0;
        if (start==end){
            if (data[start]==k)
                return 1;
            else
                return 0;
        }
        int mid = (start+end)/2;
        if (data[mid]>k)
            return binaryCount(data, k, start, mid-1);
        else if (data[mid]<k)
            return binaryCount(data, k, mid+1, end);
        else
            return binaryCount(data, k, start, mid-1) + binaryCount(data, k, mid+1, end) + 1;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        if (data.size()==0)
            return 0;
        int count = binaryCount(data, k, 0, data.size()-1);
        return count;
    }
};
