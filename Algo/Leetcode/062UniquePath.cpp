// dp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[i][j] = 1;
                else if(i==0) dp[i][j] = dp[i][j-1];
                else if(j==0) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

// Combination
class Solution {
public:
    int uniquePaths(int m, int n) {
        return(combo(m+n-2, n-1));
    }
    int factorial(int n)
    {
        int fc=1;
        for(int i=1;i<=n;++i) fc *= i;
        return fc;
    }
    int combo(int m, int n){
        return factorial(m) / (factorial(n) * factorial(m-n));
    }
};