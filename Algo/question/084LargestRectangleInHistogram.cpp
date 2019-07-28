//1. Use stack. O(N)
class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> s;
        height.push_back(0);
        int result = 0;
        for (int i = 0; i < height.size(); ) {
            if (s.empty() || height[i] > height[s.top()])
                s.push(i++);
            else {
                int tmp = s.top();
                s.pop();
                result = max(result, height[tmp] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        return result;
    }
};    

//My try. Memory limited failed.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int len = heights.size();
        if(len==0) return 0;
        
        int maxH = heights[0];
        int mid = 0;
        for(int i=1;i<len;i++){
            if(heights[i]>maxH){
                maxH = heights[i];
                mid = i;
            }
        }
        
        int l = mid, r = mid;
        res = heights[mid];
        int minH = heights[mid];
        while(l>0 || r<len-1){
            if(l==0){r++; minH = min(minH,heights[r]);}
            else if(r==len-1){l--; minH = min(minH,heights[l]);}
            else if(heights[r+1]>=heights[l-1]){r++; minH = min(minH,heights[r]);}
            else{l--; minH = min(minH,heights[l]);}
            
            res = max(res,(r-l+1)*minH);
        }
        
        if(mid!=len){
            vector<int> right(heights.begin()+mid+1,heights.end());
            res = max(res,largestRectangleArea(right));
        }
        if(mid!=0){
            vector<int> left(heights.begin(),heights.begin()+mid-1);
            res = max(res,largestRectangleArea(left));
        }
        
        return res;
    }
};