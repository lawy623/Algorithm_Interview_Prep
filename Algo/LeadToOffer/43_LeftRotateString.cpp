// 1. Partially reverse first then reverse the whole one.
class Solution {
public:
    void Reverse(string& s, int start, int end) {
        int mid = (start+end+1)/2-start;
        for(int i = 0; i<mid; i++) {
            swap(s[start+i], s[end-i]);
        }
        return;
    }
    string LeftRotateString(string str, int n) {
        if (n<=0 || str=="" || n>str.length())
            return str;

        Reverse(str, 0, n-1);
        Reverse(str, n, str.length()-1);
        Reverse(str, 0, str.length()-1);
        return str;
    }
};
