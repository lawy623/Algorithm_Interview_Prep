// my implementation
class Solution {
public:
    string decodeString(string s) {
        stack<int> st;
        int start = -1;
        int end = -1;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '[') st.push(i);
            else if(s[i] == ']' && !st.empty()){
                start = st.top(); end = i;
                break;
            }
        }

        if(start > 0){
            string s_base = s.substr(start+1, end-start-1);
            string n_copy = "";
            while(--start >=0 && isDisgit(s[start]))
                n_copy += s[start];
            reverse(n_copy.begin(), n_copy.end());
            int n = stoi(n_copy);
            string s_replace = "";
            while(n>0) {s_replace += s_base; n--;}
            return decodeString(s.replace(start+1, end-start, s_replace, 0, s_replace.length()));
        }
        return s;
    }

    bool isDisgit(char c){
        return c>='0' && c<='9';
    }
};