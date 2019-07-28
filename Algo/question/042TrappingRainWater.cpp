//1.Get two array to store left Max and right Max.
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len<=1) return 0;
        int* maxLeft = new int[len]();
        int* maxRight = new int[len]();
        
        for(int i=1;i<len;i++){
            maxLeft[i] = max(height[i-1],maxLeft[i-1]);
            maxRight[len-i-1] = max(height[len-i],maxRight[len-i]);
        }
   
        int sum=0;
        for(int i=1;i<len-1;i++){
            int h = min(maxLeft[i],maxRight[i]);
            if(h>height[i]){
                sum+=h-height[i];
            }
        }
        
        delete maxLeft;    //Remeber to delete newly assigned memory.
        delete maxRight;
        return sum;
    }
};

//2. Get the highest in the middle. From highest to left/right. Get next peak. Save place
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if(len<=1) return 0;
        int max = 0;
        for(int i =0;i<len;i++){
            if(height[i]>height[max]) max = i;
        }
        
        int sum = 0;
        for(int i =0, peak =0; i<max; i++){
            if(height[i]>peak) peak = height[i];
            else sum += peak - height[i];
        }            
        for(int i = len-1,peak=0; i>max; i--){
            if(height[i]>peak) peak = height[i];
            else sum += peak - height[i];
        }
        
        return sum;
    }
};