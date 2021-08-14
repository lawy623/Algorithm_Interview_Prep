// multi each char in nums, add 0 to end, and add string
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n1 = num1.size();
        int n2 = num2.size();

        string res = "0";
        for(int i=n2-1; i>=0; i--){
            res = addString(res, mulChar(num1, num2[i], n2-i-1));
        }
        return res;
    }

    string addString(string a, string b){
        string res = "";
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        while(i>=0 || j>=0 || carry){
            int l = i>=0?a[i--]-'0':0;
            int r = j>=0?b[j--]-'0':0;
            int sum = l+r+carry;
            carry = sum / 10;
            res += sum % 10 + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string mulChar(string s, char c, int pad){
        string res = "";
        int n = s.length()-1;
        int carry = 0;
        while(carry || n>=0){
            int r = n<0?carry:((s[n]-'0') * (c-'0')+carry);
            carry = r / 10;
            res += r % 10 + '0';
            n--;
        }
        reverse(res.begin(), res.end());
        for(int i=0; i<pad; i++) res+='0';
        return res;
    }
};