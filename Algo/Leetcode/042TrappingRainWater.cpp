//1.Get two array to store left Max and right Max.
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=1) return 0;
        int n = height.size();

        vector<int> l_max_h(n);
        l_max_h[0] = height[0];
        vector<int> r_max_h(n);
        r_max_h[n-1] = height[n-1];

        for(int i=1; i<n; i++){
            l_max_h[i] = max(height[i], l_max_h[i-1]);
            r_max_h[n-i-1] = max(height[n-i-1], r_max_h[n-i]);
        }

        int sum = 0;
        for(int i=0; i<n; i++)
            sum += min(l_max_h[i], r_max_h[i]) - height[i];
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

// 单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=1) return 0;
        int n = height.size();

        stack<int> s;
        int res = 0;
        for(int i=0; i<n; i++){
            while(!s.empty() && height[s.top()] < height[i]){
                int cur = s.top();
                s.pop();
                if(s.empty()) break;
                int l = s.top();
                int r = i;
                int h = min(height[r], height[l]) - height[cur];
                res += (r - l - 1) * h;
            }
            s.push(i);
        }
        return res;
    }
};