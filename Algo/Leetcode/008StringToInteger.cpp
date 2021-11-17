//1. Use head to keep track of first few char to be valid. Change string to int at last. 20ms.
//This is not very good as it need more space to store. And process the string with num twice.
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) {return 0;}
        bool head = true;
        int sign = 1;
        string rev = "";
        for(int i=0;i<str.length();i++){
            if(head){
                if(str[i]==' ') continue;
                else if(str[i]=='-'){head = false;sign = -1;}
                else if(str[i]=='+'){head = false;}
                else if((str[i]-'0'>=0) && (str[i]-'0'<=9)){rev += str[i];head = false;} //Actually can us isdigit()
                else break;
            }
            else{
                if((str[i]-'0'>=0) && (str[i]-'0'<=9)){rev += str[i];}
                else break;
            }
        }
        int pre = 0, res = 0; 
        for(int i=0;i<rev.length();i++){
            res = res * 10 + sign*(rev[i]-'0'); 
            if(res / 10 != pre) return sign>0? INT_MAX:INT_MIN;
            pre = res;
        }
        return res;
    }
};

//2.First the first non-space char. If next is '+' or '-', keep it. Otherwise if is num that go 
// and calculate, else stop. Save space and undo useless job.
class Solution {
public:
    int myAtoi(string str) {
        int i=0;
        if (str.empty()) {return 0;}
        int sign = 1;
        for(;i<str.length() && str[i]==' ';i++);
        
        if(str[i]=='-'){sign = -1;i++;}
        else if(str[i]=='+'){i++;}
        
        int pre = 0, res = 0; 
        for(;i<str.length() && isdigit(str[i]) ;i++){
                res = res * 10 + sign*(str[i]-'0'); 
                if(res / 10 != pre) return sign>0? INT_MAX:INT_MIN;  // This can not be used in leetcode
                pre = res;
        }
        return res;
    }
};

// more clear exit mode
class Solution {
public:
    bool isNum(char c){
        return '0' <= c && c <= '9';
    }

    int myAtoi(string s){
        int n = s.length();
        if(n==0) return 0;
        int res = 0;
        int i = 0;
        int sign = 1;
        while(i < n && s[i] == ' ')
            i++;
        if(s[i] == '-' || s[i] == '+')
            sign = s[i++]=='-'?-1:1;
        while(i < n && isNum(s[i])){
            if (res > INT_MAX / 10 || res == INT_MAX / 10 && int(s[i]-'0') > 7)
                return INT_MAX;
            if (res < INT_MIN / 10 || res == INT_MIN / 10 && int(s[i]-'0') > 8)
                return INT_MIN;
            res = res * 10 + sign * int(s[i]-'0');
            i++;
        }
        return res;
    }
};

};
