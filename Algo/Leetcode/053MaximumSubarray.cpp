//1. DP. O(N);
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, f = 0;
        for(int i=0;i<nums.size();++i){
            f = max(f + nums[i],nums[i]);  //This a already the transfer function.
            res = max(res , f);
        }
        return res;
    }    
};

//Divide and Conquer. O(NlgN).
class Solution {
public:
    int maxSubArray(vector<int>& nums, int l, int mid, int r) {
        if(l==r) return nums[l];

        int sum=0;
        int maxRSum = 0;
        for(int i=mid+1;i<=r;i++){
            sum += nums[i];
            if(sum>maxRSum){
                maxRSum = sum;
            }
        }
        sum=0;
        int maxLSum = 0;
        for(int i=mid-1;i>=0;i--){
            sum += nums[i];
            if(sum>maxLSum){
                maxLSum = sum;
            }
        }
        int total = nums[mid] + maxLSum + maxRSum;
        if(mid<r && mid>l) return max(max(total,maxSubArray(nums,l,(l+mid-1)/2,mid-1)),maxSubArray(nums,mid+1,(r+mid+1)/2,r));
        else if(mid<r) return max(total,maxSubArray(nums,mid+1,(r+mid+1)/2,r));
        else return max(total,maxSubArray(nums,l,(l+mid-1)/2,mid-1));
    }
    
    int maxSubArray(vector<int>& nums){
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        
        return maxSubArray(nums,0,(nums.size()-1)/2,nums.size()-1);
    }
};