// 1. dp[][] with two dim array. dp[m][sum] is the number of ways that the first m coins make sum.
// O(kn) time, O(kn) space.
class Coins {
public:
    int countWays(int n) {
        int coins[4] = {1, 5, 10, 25};
        int** dp = new int*[4];
        for(int i=0; i<4; i++)
            dp[i] = new int[n+1];
        for (int j = 0; j <= n; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i < 4; i++) {
            for (int j = 0; j <= n; j++) {
                int t = j - coins[i];
                if (t >= 0) {
                    dp[i][j] = (dp[i - 1][j] + dp[i][t]) % 1000000007;
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[3][n];
    }
};


// 2. dp[]. Similar idea but more recursive. Used only one array to store results.
// O(kn) time, O(n) space.
class Coins {
public:
    int countWays(int n) {
        if (n<=0)
            return 0;
        int coins[4] = {1,5,10,25};
        int* dp = new int[n+1];
        dp[0]=1;
        for(int i=0;i<4;i++) {
            for (int j=coins[i];j<=n;j++)
                dp[j] = (dp[j]+dp[j-coins[i]])%1000000007;
        }
        return dp[n];
    }
};
