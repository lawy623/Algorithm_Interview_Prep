//1.Easily use stack. O(N)
class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        
        map<char,char> temp = {{')','('},{']','['},{'}','{'}};
        
        stack<char> st;
        
        for(char c : s){
            if(st.empty()) st.push(c);
            else{
                if(st.top()==temp[c]) st.pop();
                else st.push(c);  
            }    
        }
        
        return st.empty();
    }
};