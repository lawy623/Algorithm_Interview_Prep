//1.BR. O(N^2). 1396ms
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                maxArea = max(maxArea, min(height[i],height[j])*(j-i));
            }
        }
        return maxArea;
    }
};

//2. TwoPointer 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0, r=height.size()-1;
        int maxArea = min(height[l],height[r])*(r-l);
        while(l<r){  // 证明用的归纳法， 实际上短边不可能作为最优的边界了，必须向内移动
            maxArea = max(maxArea, min(height[l],height[r])*(r-l) );
            if(height[l]>height[r]) r--;
            else l++;
        }
        return maxArea;
    }
};