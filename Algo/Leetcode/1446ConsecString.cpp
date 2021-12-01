class Solution {
public:
    int maxPower(string s) {
        int n = s.length();
        int i = 1;
        int max_len = 1;
        if(n<=1) return n;

        int l = 1;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                l++;
                max_len = max(max_len, l);
            } else
            l = 1;
        }

        return max_len;
    }
};