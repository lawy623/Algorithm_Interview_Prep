//1. Similar to 10-base addition.
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res = "";
        int i=a.length()-1;
        int j=b.length()-1;
        while(j>=0 || i>=0 || carry){
            int n1 = i<0? 0:a[i]-'0';
            int n2 = j<0? 0:b[j]-'0';
            int sum = (n1+n2+carry)%2;
            carry = (n1+n2+carry)/2;
            res = char(sum + '0') + res;
            i--;j--;
        }
        return res;
    }
};