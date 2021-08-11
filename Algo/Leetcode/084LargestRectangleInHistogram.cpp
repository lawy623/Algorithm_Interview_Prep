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
        if(heights.size()==0) return 0;
        int n = heights.size();

        int max_a = 0;
        for(int i=0; i<n; i++){
            int l = i;
            int r = i;
            int h = heights[i];
            while(l>=0 && heights[l]>=heights[i]) l--;
            while(r<n && heights[r]>=heights[i]) r++;
            max_a = max(max_a, (r-l-1)*h);
        }
        return max_a;
    }
};

// 单调栈。保存左右边界
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> l(n), r(n, n);

        stack<int> s;
        for(int i=0; i<n; i++){
            while(!s.empty() && heights[s.top()] > heights[i]){ //每次都推入更大的数值，单调递增栈。特点是会返回两边比当前小的第一个数
                r[s.top()] = i;
                s.pop();
            }
            l[i] = s.empty()?-1:s.top();
            s.push(i);
        }

        int res = 0;
        for(int i=0; i<n; i++)
            res = max(res, (r[i]-l[i]-1)*heights[i]);
        return res;
    }
};