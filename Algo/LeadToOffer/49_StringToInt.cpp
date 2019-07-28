// Consider case of: "", "+2", "-1", "23", invalid char, overflow.
class Solution {
public:
    int StrToInt(string str) {
        long long res = 0;
        if (str.length()==0)
            return 0;
        int sign = 1;
        int start = 0;
        if (str[0]=='+'){
            sign = 1;
            start = 1;
        } else if (str[0]=='-') {
            sign = -1;
            start = 1;
        }

        for (int i = start; i < str.length(); i++) {
            int c = int(str[i]-'0');
            if (c<0 || c>9)
                return 0;
            res = res * 10 + c;
            if ((sign==1 && res>INT_MAX) || (sign==-1 && res<INT_MIN) )
                return 0;
        }
        return int(res) * sign;
    }
};
