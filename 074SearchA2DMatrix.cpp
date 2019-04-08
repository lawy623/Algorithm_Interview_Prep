//1. Binary search. Just in matrix. O(lg(m+n)).
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        if(n==0) return false;        
        
        int l = 0, r = n*m - 1;
        while(l<=r){
            int mid = (l+r)/2;
            int value = matrix[mid/n][mid%n];
            
            if(value<target) l = mid+1;
            else if(value>target) r = mid - 1;
            else {return true;}
        }
        
        return false;
    }
};