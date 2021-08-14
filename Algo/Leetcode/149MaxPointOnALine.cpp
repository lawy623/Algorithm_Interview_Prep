// O(n) space, O(n^2) time. Count the rates.
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=2) return n;

        int max_count = 2;
        for(int i=0; i<n; i++){
            map<double, int> m;
            for(int j=0; j<n; j++){
                if(i==j) continue;
                double rate = (double)points[j][1] - points[i][1];
                rate /= (double)(points[j][0] - points[i][0]);
                if(m.find(rate)==m.end()) m[rate] = 2;
                else m[rate] += 1;
                max_count = max(max_count, m[rate]);
            }
        }
        return max_count;
    }
};