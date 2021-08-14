class Solution {
public:
    string addStrings(string num1, string num2) {
        string res = "";
        int i = num1.length()-1;
        int j = num2.length()-1;
        int carry = 0;
        while(i>=0 || j>=0 || carry){
            int l = i>=0?num1[i--]-'0':0;
            int r = j>=0?num2[j--]-'0':0;
            int sum = l+r+carry;
            carry = sum / 10;
            res += sum % 10 + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};