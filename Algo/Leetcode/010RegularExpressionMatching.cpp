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
    bool isMatch(string s, string p){
        int n = s.length();
        int m = p.length();
        vector<vector<bool> > dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;   // dp[i][j] means whether s[:i] and p[:j] is matched
        for(int i=1; i<m+1; i++){
            if(p[i-1] == '*' && dp[0][i-2])   // dp[0][*] always gets empty s to compare
                dp[0][i] = true;
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                if(p[j-1] == '.' || p[j-1] == s[i-1])        // s.at(i) is matched with p.at(j).
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*')
                    if(p[j-2] == '.' || p[j-2] == s[i-1])
                        dp[i][j] = dp[i][j-2] || dp[i][j-1] || dp[i-1][j];   // * 让p[j-2]出现 0次， 1次， 2次或以上
                    else
                        dp[i][j] = dp[i][j-2];
            }
        }
        return dp[n][m];
    }
};