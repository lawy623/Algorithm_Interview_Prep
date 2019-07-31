// 1. Use isSubstring function. If s2 is rotate of s1, s2 must be substring of s1.
// O(n) time. O(n) space for s1+s1.
class ReverseEqual {
public:
    bool isSubstring(string s1, string s2) {
        if (s1.length()<s2.length())
            return false;
        for(int i=0; i<=s1.length()-s2.length(); i++) {
            int j = 0;
            while (s1[i]==s2[j] && j<s2.length() && i<s1.length()) {
                i++;
                j++;
            }
            if (j==s2.length())
                return true;
        }
        return false;

    }
    bool checkReverseEqual(string s1, string s2) {
        if(s1.length()!=s2.length())
            return false;
        return isSubstring(s1+s1, s2);
    }
};
