// very comprehensive consideration
class Solution {
public:
    bool isNumber(string s) {
        int n = s.length();
        if(n==0) return false;
        int i = 0; while(i<n && s[i]==' ') i++;
        int j = n-1; while(j>=0 && s[j]==' ') j--;
        if(i==j) return isDigit(s[j]);

        bool showNum = false;
        bool showE = false;
        bool showDot = false;
        for(int k=i; k<=j; k++){
            if(isDigit(s[k])){
                showNum = true;
            } else if(s[k] == '+' || s[k] == '-'){
                if(k>i && s[k-1]!='e' && s[k-1]!='E') return false;  // 加减号只能在e的后面或者i的位置
            } else if(s[k] == '.'){
                if(showDot || showE) return false;    // .只能在e的前面，出现过e或者出现过.都不行
                showDot = true;
            } else if(s[k] == 'e' || s[k] == 'E'){
                if(showE || !showNum) return false;   // e只能出现在数字后面
                showNum = false;                      // 要确保e后面还有数字
                showE = true;
            }
            else return false;
        }
        return showNum;
    }

    bool isDigit(char c){
        return c>='0' && c<='9';
    }
};