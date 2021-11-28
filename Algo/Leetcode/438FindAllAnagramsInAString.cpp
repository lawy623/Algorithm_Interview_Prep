// Use a vector to comp each sliding window
// Time is O(m + (n-m) * 26), Space is O(26)
class Solution {
public:
    bool checkAllZero(vector<int> count){
        for(int i:count)
            if(i!=0) return false;
        return true;
    }

    vector<int> findAnagrams(string s, string p){
        vector<int> res;
        int n = s.length();
        int m = p.length();
        if(m > n) return res;

        vector<int> count(26, 0);

        for(int i=0; i<m; i++){
            count[p[i]-'a'] -= 1;
            count[s[i]-'a'] -= 1;
        }

        if(checkAllZero(count)) res.push_back(0);

        for(int i=m; i<n; i++){
            count[s[i]-'a'] -= 1;
            count[s[i-m]-'a'] += 1;
            if(checkAllZero(count))
                res.push_back(i-m+1);
        }

        return res;
    }
};


// You do not need to comp the whole array each pos, but use a single diff value to count
// The value is changed based on the coming change
// Time is O(m + 26 + (n-m)), Space is O(26)
class Solution {
public:
    int countDiff(vector<int> count){
        int diff = 0;
        for(int i:count){
            if(i!=0)
                diff += 1;
        }
        return diff;
    }

    vector<int> findAnagrams(string s, string p){
        vector<int> res;
        int n = s.length();
        int m = p.length();
        if(m > n) return res;

        vector<int> count(26, 0);
        for(int i=0; i<m; i++){
            count[p[i]-'a'] -= 1;
            count[s[i]-'a'] -= 1;
        }
        int diff = countDiff(count);

        if(diff==0) res.push_back(0);

        for(int i=m; i<n; i++){
            if(count[s[i-m]-'a']==-1)       // the leaving one will lead to a reduced diff
                diff -= 1;
            else if(count[s[i-m]-'a']==0)   // the leaving one will lead to a increased diff
                diff += 1;
            count[s[i-m]-'a'] += 1;

            if(count[s[i]-'a'] == 1)        // the coming one will lead to a reduced diff
                diff -= 1;
            else if(count[s[i]-'a']==0)     // the coming one will lead to a increase diff
                diff += 1;
            count[s[i]-'a'] -= 1;

            if(diff == 0)
                res.push_back(i-m+1);
        }

        return res;
    }
};