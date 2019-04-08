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
        while(l<r){
            if(height[l]>height[r]){
                r--;
            }
            else
                l++;
            maxArea = max(maxArea, min(height[l],height[r])*(r-l) );
        }
        return maxArea;
    }
};