//1.BruteForce O(n^3) time. O(1) Space
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<1) return "";
        int len = s.length();
        int maxLen = 0;
        string ans = "";
        for(int i=0;i<len;i++){
            for(int j=i;j<len;j++){
                if(checkPa(s,i,j) && (j-i+1)>maxLen) {
                    maxLen = max(maxLen,j-i+1);
                    ans = s.substr(i,j-i+1);
                    //cout<<"i: "<<i<<" j: "<<j<<" max len: " <<maxLen<<endl;
                }    
            }
        }
        return ans;
    }
    
    bool checkPa(string s, int start, int end){
        for(int i=0;i< (end-start+1)/2;i++){
            if(s[start+i]!=s[end-i]) return false;
        } 
        return true;
    }
};

//2.dp动态规划，时间空间都是o(^2)
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<1) return "";
        int dp[s.length()][s.length()]={0};
        
        int max = 0;
        int left=0;
       
        for(int i=0;i<s.length();i++){
            for(int j=0;j<i+1;j++){
                dp[j][i]= (s[i]==s[j]) && (i-j<2 || dp[j+1][i-1])  ;
                if(dp[j][i] && max<i-j+1){
                    left=j;
                    max = i-j+1;
                }
            }
        }

        return s.substr(left,max);
    }

//3.中心延展查找。 O(n^2) Time, O(1) Space.
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<1) return "";
        int start=0, end =0;
        for(int i=0;i<s.length(); i++){
            int len1 = expandAroundCenter(s,i,i);
            int len2 = expandAroundCenter(s,i,i+1);
            int len = max(len1,len2);
            
            if(len>end - start){
                start = i-(len-1)/2;
                end = i+len/2;
            }
        }
        return s.substr(start,end-start+1); 
    }
    
private:
    int expandAroundCenter(string s, int left, int right) {
        int L = left;
        int R = right;
        while( L>= 0 && R<s.length() && s[L] == s[R]){
            L--;
            R++;
        }
        return R-L-1; //Actually after a expand, the while loop will stop. So len should be R-L-1.
    }
    
};

//4. Manacher Algorithm. O(N) Time. *Hard to understand.
class Solution {
public:
    string longestPalindrome(string s) {
        string t ="$#";
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += '#';
        }
        int p[t.size()] = {0}, id = 0, mx = 0, resId = 0, resMx = 0;
        for (int i = 0; i < t.size(); ++i) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                id = i;
            }
            if (resMx < p[i]) {
                resMx = p[i];
                resId = i;
            }
        }
        return s.substr((resId - resMx) / 2, resMx - 1);
    }
};