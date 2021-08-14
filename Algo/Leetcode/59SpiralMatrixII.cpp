// set 4 bound and remove in direction. When it is square it is ok to do this. When it is rectangle, cant not do it.
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0; int r = n-1; int u = 0; int d = n-1;
        int num = 1;
        vector<vector<int>> res(n, vector<int>(n));
        while(num <= n*n){
            for(int i=l; i<=r; i++) res[u][i] = num++;
            u++;
            for(int i=u; i<=d; i++) res[i][r] = num++;
            r--;
            for(int i=r; i>=l; i--) res[d][i] = num++;
            d--;
            for(int i=d; i>=u; i--) res[i][l] = num++;
            l++;
        }
        return res;
    }
};