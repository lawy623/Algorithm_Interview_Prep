//1. Use recurrsion. Go through the n-1 string. O(N^2)
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        
        string preS = countAndSay(n-1);
        string newS = "";
        int cur = 1;
        int count = 1;
        while(cur<preS.length()){
            if(preS[cur]==preS[cur-1]){
                count++;
                cur++;
            }
            else{
                newS += char(count + '0');
                newS += preS[cur-1];
                count = 1;
                cur++;
            }
        }
        newS += char(count + '0');
        newS += preS[cur-1];
        return newS;
    }
};