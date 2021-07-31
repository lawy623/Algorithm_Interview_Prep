class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.length();
        int left = 0; int right = n - 1;
        while(left <= right && s[left] == ' ') left++;
        while(left <= right && s[right] == ' ') right--;

        int i = left;
        stack<char> st;
        string res;
        while(i<right){
            if(s[i] == ' '){
                while(!st.empty()){
                    res += st.top();
                    st.pop();
                }
                res += ' ';
                i++;
                while(s[i]==' ') i++;
            } else{
                st.push(s[i++]);
            }
        }
        //last word
        st.push(s[i]);
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};