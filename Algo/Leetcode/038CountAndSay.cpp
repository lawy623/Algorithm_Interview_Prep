//1. Use recursion. Go through the n-1 string. O(N^2)
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string lastStr = countAndSay(n-1);

        string res = "";
        int i = 0;
        int len = lastStr.length();
        while(i<len){
            int j = i+1;
            while(j<len && lastStr[j]==lastStr[j-1]) j++;
            int new_len = j-i;
            char new_c = lastStr[i];
            res += to_string(new_len);
            res += new_c;
            i = j;
        }
        return res;
    }
};