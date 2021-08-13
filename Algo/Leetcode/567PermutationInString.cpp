// Sliding window
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> m;
        for(char s:s1) m[s]++;

        int l = 0; int r = 0;
        while(r<s2.length()){
            char c = s2[r++];
            m[c]--;
            while(l<r && m[c]<0)  // c is appearing more
                m[s2[l++]]++;
            if(r-l==s1.size()) return true;  // each time we control m[c] is not less than 0, it won't appear more. When size is equal(r++ already), it will be exactly the same
        }
        return false;
    }
};