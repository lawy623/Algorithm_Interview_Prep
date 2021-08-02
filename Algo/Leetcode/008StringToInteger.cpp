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
                if(res / 10 != pre) return sign>0? INT_MAX:INT_MIN;
                pre = res;
        }
        return res;
    }
};

// more clear exit mode
class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        if(n==0) return 0;
        int move = 0;
        while(move<n && str[move]==' ') move++;
        if(move==n) return 0;
        int sign = 1;
        if(str[move] == '-'){
            sign = -1;
            move++;
        } else if(str[move] == '+'){
            move++;
        }
        if(move==n) return 0;

        int res = 0;
        while(move<n && isNum(str[move])){
            if(res>INT_MAX/10 || ((res==INT_MAX/10) && str[move] > '7'))
                return sign>0?INT_MAX:INT_MIN;
            res = 10*res + (str[move++]-'0');
        }
        return sign*res;
    }

    int isNum(char c){
        if(c-'0' >=0 && c-'0'<=9) return true;
        else return false;
    }

};
