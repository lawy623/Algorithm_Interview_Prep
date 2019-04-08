//1. Two Pointer sliding window. O(N)
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty()) return "";
        if(s.size()<t.size()) return "";
        
        int c1[256]={0};
        int c2[256]={0};
        
        for(int i=0;i<t.length();i++) c2[t[i]]++;
        
        int minW = INT_MAX, minId = 0;
        
        int pStart = 0;
        int appear = 0;
        
        for(int pEnd=0;pEnd<s.length();pEnd++){
            if(c2[s[pEnd]]>0){
                c1[s[pEnd]]++;
                if(c1[s[pEnd]]<=c2[s[pEnd]]) appear++;   //The second time when pEnd move, appear will not move.
            }
            if(appear==t.size()){
                while(c1[s[pStart]]>c2[s[pStart]] || c2[s[pStart]]==0){
                    c1[s[pStart]]--;
                    pStart++;
                }
                if(minW > pEnd - pStart +1){
                    minW = pEnd - pStart +1;
                    minId = pStart;
                }
            }
        }
        
        if(minW == INT_MAX) return "";
        else return s.substr(minId,minW);
    }
};