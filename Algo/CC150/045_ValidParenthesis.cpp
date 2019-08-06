class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        if (n==0)
            return true;
        stack<char> s;
        for(int i=0; i<n; i++) {
            if (!s.empty() && s.top()=='(' && A[i]==')')
                s.pop();
            else
                s.push(A[i]);
        }
        return s.empty();
    }
};
