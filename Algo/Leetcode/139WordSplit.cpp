// dp. O(n^2) time, O(n) space
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> m;
        int n = s.length();
        for(auto w:wordDict) m.insert(w);
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                if(dp[j] && m.find(s.substr(j, i-j))!=m.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};