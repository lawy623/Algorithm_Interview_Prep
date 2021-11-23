// 两种情况。
// 完全相等的时候， s里面需要有重复字符
// 不完全相等的时候， s和goal的字符dict必须相同， 同时只能恰好有两个字符有差别
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) return false;
        if (s == goal){
            vector<int> m(256, 0);
            for(char c:s){
                m[c] += 1;
                if(m[c] > 1) return true;
            }
            return false;
        } else{
            vector<int> m(256, 0);
            int countDiff = 0;
            for(int i=0; i<s.length(); i++){
                m[s[i]] += 1;
                m[goal[i]] -= 1;
                countDiff += (s[i] != goal[i]);
            }

            for(int i=0; i<256; i++){
                if(m[i] > 0) return false;
            }
            return countDiff == 2;
        }
    }
};