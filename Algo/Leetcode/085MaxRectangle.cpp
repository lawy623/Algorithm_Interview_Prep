// O(m) space, O(mn) time
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        if(col==0) return 0;
        vector<int> height(col, 0);

        int max_area = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            max_area = max(max_area, maxRec(height));
        }
        return max_area;
    }

    int maxRec(vector<int>& height){
        stack<int> s;
        int n = height.size();
        vector<int> l(n);
        vector<int> r(n, n);

        for(int i=0; i<n; i++){
            while(!s.empty() && height[s.top()] > height[i]){
                r[s.top()] = i;
                s.pop();
            }
            l[i] = s.empty()?-1:s.top();
            s.push(i);
        }

        int max_area = 0;
        for(int i=0; i<n; i++){
            max_area = max(max_area, (r[i]-l[i]-1)*height[i]);
        }
        return max_area;
    }
};