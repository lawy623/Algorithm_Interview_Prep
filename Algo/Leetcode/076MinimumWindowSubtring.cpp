class Solution {
public:
    string minWindow(string s, string t) {
        int min_len = INT_MAX; int min_start = 0;
        vector<int> c1(256, 0);
        vector<int> c2(256, 0);
        for(auto c:t) c2[c] += 1;

        int count = 0; int start = 0;
        for(int end=0; end<s.length(); end++){
            if(c2[s[end]] > 0){
                c1[s[end]]++;
                if(c1[s[end]] <= c2[s[end]]) count++;
            }

            if(count==t.length()  && c2[s[end]]>0){ // will only successful if get the count
                while(c2[s[start]]==0 || c1[s[start]] > c2[s[start]]){
                    c1[s[start]]--;
                    start++;
                }
                if(end-start+1 < min_len){
                    min_len = end - start + 1;
                    min_start = start;
                }
            }
        }
        if(min_len == INT_MAX) return "";
        return s.substr(min_start, min_len);
    }
};