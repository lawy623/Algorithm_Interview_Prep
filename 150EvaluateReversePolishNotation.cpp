//1. Use stack. O(N)
class Solution {
public:
    bool checkOp(string s){
        return (s.length()==1 && string("+-*/").find(s) != string::npos);  //String find.
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        if(tokens.size() == 0) return 0;
        
        for(string s : tokens){
            if(!checkOp(s)){
                st.push(s);
            }
            else{ 
                int a = stoi(st.top());  //string to int
                st.pop();
                int b = stoi(st.top());
                st.pop();
                if(s=="+"){b += a;}
                else if(s=="*"){b *= a;}
                else if(s=="-"){b -= a;}
                else{b /= a;}
                st.push(to_string(b));  //int to string.
            }
        }
        return stoi(st.top());
    }
};