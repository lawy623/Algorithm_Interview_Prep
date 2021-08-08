// sort. O(nlogn)
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};

//Use dict. O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> m(256, 0);
        for(auto c:s) m[c]+=1;
        for(auto c:t) m[c]-=1;
        for(auto c:m){
            if (c!=0) return false;
        }
        return true;
    }
};