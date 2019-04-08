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