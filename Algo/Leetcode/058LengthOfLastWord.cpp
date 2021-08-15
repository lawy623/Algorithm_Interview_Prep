// reverse and two pointer
class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(), s.end());
        int i = 0;
        while(i<s.length() && s[i]==' ') i++;
        if(i==s.length()) return 0;
        int j = i;
        while(j<s.length() && s[j]!=' ') j++;
        return j-i;
    }
};