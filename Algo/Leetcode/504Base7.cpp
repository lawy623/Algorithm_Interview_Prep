class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0) return "0";
        string s = "";
        if(num < 0) {s='-'; num*=-1;}
        string res = "";
        while(num>0){
            res += (num % 7 + '0');
            num /= 7;
        }
        reverse(res.begin(), res.end());
        return s+res;
    }
};