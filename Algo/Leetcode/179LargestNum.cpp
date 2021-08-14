class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        string s = "";
        for(auto n:nums) s += to_string(n);
        int start = 0;
        while(start < s.length() && s[start]=='0') start++;
        if(start == s.length()) return "0";
        return s.substr(start);
    }

    static bool comp(int a, int b){
        string m = to_string(a) + to_string(b);
        string n = to_string(b) + to_string(a);
        return m>n;
    }
};