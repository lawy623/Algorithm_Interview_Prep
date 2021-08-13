class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0; i<s.length(); i++){
            count += countPal(s, i, i);
            count += countPal(s, i, i+1);
        }
        return count;
    }

    int countPal(string s, int l, int r){
        while(l>=0 && r<s.length() && s[l] == s[r])
            {l--; r++;}
        return (r-l)/2;  // count will be (r-l-1)+1 / 2
    }
};