class Finder {
public:
    int findElement(vector<int> A, int n, int x) {
        int low = 0;
        int high = n-1;
        int mid = 0;
        while(low<=high) {
            mid = (low+high) / 2;
            if (A[mid]==x) return mid;
            if (A[mid]<x) {
                if (A[mid]<A[low]&&x>=A[low]) high=mid-1;
                else low = mid+1;
            } else {
                if (A[mid]>A[low]&&x<A[low]) low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
};
