// use stack
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length() == 0) return 0;
        stack<int> st;
        st.push(-1);

        int max_len = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '(') st.push(i);
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else max_len = max(max_len, i-st.top());
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