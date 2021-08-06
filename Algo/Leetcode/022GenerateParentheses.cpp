
//1.Recursion. When left is not more than n, keep puting (. When left is more than right, put right. 
class Solution {
    public:
        void generator(vector<string> &ans, string s, int l, int r,  int n) {
            if(l==n) {
                ans.push_back(s.append(n-r, ')'));
                return;
            }
            generator(ans, s+"(", l+1, r, n);
            if(l>r) generator(ans, s+")", l, r+1, n);

        }
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            generator(ans, "", 0, 0, n);
            return ans;
        }
};


//2.Recurrsion. Easier to understand.
class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string> ans;
            if(n==0) return vector<string>(1,"");
            if(n==1) return vector<string>(1,"()");
            
            for(int i=0;i<n;i++){
                for(auto inner : generateParenthesis(i)){
                    for(auto outer : generateParenthesis(n-1-i)){
                        ans.push_back("("+inner+")"+outer);
                    }
                }
            }
            return ans;
        }     
};

// dfs
class Solution {
public:

    vector<string> res;
    vector<string> generateParenthesis(int n) {
        if(n==0) return res;
        dfs("", n, n);
        return res;
    }

    void dfs(string s, int l, int r){
        if(r==0){
            res.push_back(s);
            return;
        }
        else if(l==0)
            dfs(s+')', 0, r-1);
        else if(l==r)
            dfs(s+'(', l-1, r);
        else{
            dfs(s+'(', l-1, r);
            dfs(s+')', l, r-1);
        }

    }
};