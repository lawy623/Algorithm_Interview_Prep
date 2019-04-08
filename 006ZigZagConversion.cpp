//1. Use a curRow indicator and a direction indicator to keep track the rows.
// O(N) time and O(N) spcae. 28ms.
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows>=s.length() || numRows==1 || s=="") return s;
        int curRow = 0;
        vector<string> rows( min(int(s.length()),numRows) );
        bool direc = false;
        
        for(int i=0;i<s.length();i++){
            rows[curRow].push_back(s[i]);
            if(curRow==0){curRow +=1;direc = !direc;}
            else if(curRow ==numRows-1){curRow -=1;direc = !direc;}
            else{curRow += direc?1:-1;}
        }
        string res="";
        for(int i=0;i<numRows;i++){
            res += rows[i];
        }
        return res;
    }
};

//Optimized by some syntax. 16ms
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows>=s.length() || numRows==1 || s=="") return s;
        int curRow = 0;
        vector<string> rows( numRows) ;
        //or Use
        //   string rows[numRows] here
        bool direc = false;
        
        for(char c : s){. //Here is a syntax change.
            rows[curRow].push_back(c);
            if(curRow==0 || curRow == numRows-1){direc = !direc;} //Group the conditions.
            curRow += direc?1:-1;
        }
        string res="";
        for(string row : rows). //Here is a syntax
            res += row;
        return res;
    }
};


//2.直接计算出每个row应该在string中的位置，按照row输出. 16ms. O(1) Space
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows>=s.length() || numRows==1 || s=="") return s;
        
        string res;
        int step = 2*numRows - 2;
        
        for(int i=0;i<numRows;i++){
            for(int j=0;j+i<s.length();j+=step){
                res += (s[i+j]);
                if(i!=0 && i!=numRows-1 && j-i+step < s.length()){
                    res += (s[j-i+step]);
                }
            }
        }
        return res;
    }
};