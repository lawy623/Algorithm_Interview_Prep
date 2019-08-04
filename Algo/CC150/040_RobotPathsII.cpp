// 1. dp. Need to check map[0][0] as well.
class Robot {
public:
    int countWays(vector<vector<int> > map, int x, int y) {
        vector<vector<int> > dp;
        for(int i=0; i<x; i++) {
            vector<int> row;
            for(int j=0; j<y; j++) {
                row.push_back(0);
            }
            dp.push_back(row);
        }
        if (map[0][0]!=1)
            dp[0][0] = 0;
        else
            dp[0][0] = 1;
        for (int i=1; i<x; i++) {
            if(map[i][0]!=1)
                dp[i][0] = 0;
            else
                dp[i][0] = dp[i-1][0];
        }
        for (int j=1; j<y; j++) {
            if(map[0][j]!=1)
                dp[0][j] = 0;
            else
                dp[0][j] = dp[0][j-1];
        }
        for(int i=1; i<x; i++){
            for(int j=1; j<y; j++){
                if (map[i][j]!=1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[x-1][y-1];
    }
};
