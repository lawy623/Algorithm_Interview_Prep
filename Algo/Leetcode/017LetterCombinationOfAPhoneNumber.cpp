//1. BFS. Get all previous. Then add the last.
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> all={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        vector<string> ans,temp;
        if(digits.empty()) return ans;
        
        for(int i=0;i<digits.size();i++){
            int c = digits[i] - '0';
            if(ans.size()==0) ans.push_back("");
            for(int j=0;j<ans.size();j++){
                string ret = ans[j];
                for(int k=0;k<all[c].length();k++){
                    temp.push_back(ans[j]+all[c][k]);
                }
            }
            ans = temp;
            temp = {};
        }
        return ans;
    }
};

//2.DFS
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.size() == 0) return ret;
        string tmpstr(digits.size(), ' ');
        letterCombinations_helper(digits, 0, tmpstr, ret);
        return ret;
    }
    
private:
    vector<vector<char> > phonetable;
    void letterCombinations_helper(string digits, int index, string tmpstr, vector<string>& ret)
    {
        string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(index == digits.size())
        {
            ret.push_back(tmpstr);
            return;
        }
 
        for(int i = 0; i < numap[digits[index] - '0'].size(); i++)
        {
            tmpstr[index] = numap[digits[index] - '0'][i];
            letterCombinations_helper(digits, index+1, tmpstr, ret);
        }
        
        return;
    }
};
