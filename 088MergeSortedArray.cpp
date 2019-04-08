//1. Sort from the back. Which does not affect unsorted nums. O(m+n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i=m-1, j=n-1, cur=m+n-1;
        while(i>=0 && j>=0){
            nums1[cur--] = nums1[i]>=nums2[j]? nums1[i--]:nums2[j--];
        }
        while(j>=0){
            nums1[cur--] = nums2[j--];   //if i>=0 but j<0. Doesn't matter. Keep nums1's rest
        }
    }
};