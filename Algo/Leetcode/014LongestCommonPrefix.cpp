//1. Recursion. firstChar+LCP(substr(1)). 4ms
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        if(strs.size()==1) return strs[0];
        if(strs[0].length()==0) return "";

        string res = "";
        char first = strs[0][0];
        
        res += first;
        for(int i=0;i<strs.size();i++){
            if(strs[i][0]!=first) return "";
            strs[i] = strs[i].substr(1);
        }
        
        return res+longestCommonPrefix(strs);
    }
};

// For loops
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0) return "";
        if(n==1) return strs[0];

        string res = "";
        int pos = 0;
        while(true){
            if(pos>=strs[0].length()) return res;
            char c = strs[0][pos];
            for(int i=1; i<strs.size(); i++){
                if(pos >= strs[i].length() || strs[i][pos]!=c) return res;
            }
            res += c;
            pos++;
        }
        return res;
    }
};

// sort and compare first and end
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0) return "";
        if(n==1) return strs[0];

        sort(strs.begin(), strs.end());
        int pos = 0;
        while(true){
            if(pos < strs[0].length() && pos < strs[strs.size()-1].length() && strs[0][pos]==strs[strs.size()-1][pos]) pos++;
            else break;
        }
        return strs[0].substr(0, pos);
    }
};