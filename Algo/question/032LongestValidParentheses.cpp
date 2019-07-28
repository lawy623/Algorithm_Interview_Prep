class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0, last = -1;
        stack<int> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                if(st.empty()){
                    last = i;
                }
                else{
                    st.pop();
                    if(st.empty()){
                        max_len = max(max_len, i - last);
                    }
                    else{
                        max_len = max(max_len, i - st.top());
                    }
                }
            }
        }
        return max_len;
    }
};


class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> f(s.length(),0);
        int res = 0;
        for(int i=s.length()-2;i>=0;i--){
            int match = i + f[i+1] + 1;
            if(s[i]=='(' && match < s.length() && s[match]==')'){
                f[i] = f[i+1] + 2;
                if(match+1<s.length()){
                    f[i]+=f[match+1];
                }  
            }
            res = max(res,f[i]);
        }
        return res;
    }
};