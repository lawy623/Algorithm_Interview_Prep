
//1. Keep retaining a 10bit num. Find it in set.
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> res;
        unordered_set<int> st;
        int cur = 0, i = 0;
        while (i < 9) cur = cur << 3 | (s[i++] & 7);
        while (i < s.size()) {
            cur = ((cur << 3)  & 0x3ffffff8) | (s[i++] & 7);
            if (st.count(cur)) res.insert(s.substr(i - 10, 10));
            else st.insert(cur);
        }
        return vector<string>(res.begin(), res.end());
    }
};