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
    string longestCommonPrefix(vector<string>& strs){
        int n = strs.size();
        if(n==1) return strs[0];            // you need this otherwise it stuck.
        int i = 0;
        while(true){
            for(int j=1; j<strs.size(); j++){
                if(i>=strs[j].size() || i>=strs[0].size() || strs[0][i] != strs[j][i])
                    return strs[0].substr(0, i);
            }
            i++;
        }
        return "";
    }
};

// sort and compare first and end
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        sort(strs.begin(), strs.end());   // The sort here may takes much longer time
        int n = strs.size();
        if(n==1) return strs[0];

        int i=0;
        while(i<strs[0].length() && i<strs[n-1].length()){
            if(strs[0][i] == strs[n-1][i])
                i++;
            else
                break;
        }
        return strs[0].substr(0, i);
    }
};