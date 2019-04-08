//1.recursion. Time O( (T+P)2^(T+P/2) ). 60ms
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        
        bool firstMatch = !s.empty() && (s[0]==p[0] || p[0]=='.');
        
        if(p.length()>=2 && p[1] == '*'){
            return isMatch(s,p.substr(2)) || (firstMatch && isMatch(s.substr(1),p)) ;
        }else{
            return ( firstMatch && isMatch(s.substr(1),p.substr(1)) );
        }
    }
};


//2. dp . O(T+P). 8ms
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        int dp[m+1][n+1];
        for(int i=0;i<m;i++) dp[i][n] = false;
        //Another initial
        //vector<vector<bool>> dp(m + 1, vector<bool> (n + 1, false));
        dp[m][n] = true;
        
        for(int i = m; i >=0; i--){
            for(int j = n-1; j >= 0; j--){
                bool firstMatch =  p[j]==s[i] || p[j]=='.';
                if(j+1<n && p[j+1]=='*'){
                    dp[i][j] = dp[i][j+2] || firstMatch && i<m && dp[i+1][j];
                }
                else
                    dp[i][j] = firstMatch && i<m && dp[i+1][j+1];
            }
        }
        return dp[0][0];
    }
};