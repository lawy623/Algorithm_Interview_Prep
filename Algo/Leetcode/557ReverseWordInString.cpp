class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;
        int j = 0;
        string res(s);
        while(i < n){
            if(s[i] == ' ') i++;
            else{
                j = i;
                while(j<n && s[j]!=' ') j++;
                revStr(res, i, j-1);
                i = j;
            }
        }
        return res;
    }

    void revStr(string& s, int i, int j){
        while(i<j)
            swap(s[i++], s[j--]);
        return;
    }
};