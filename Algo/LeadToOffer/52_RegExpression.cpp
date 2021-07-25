// Use recursion, otherwise it is too difficult.
class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if (*str=='\0' && *pattern=='\0')
            return true;
        if (*str!='\0' && *pattern=='\0')
            return false;
        if ( *(pattern+1)!= '*') {
            if (*str==*pattern || (*str!='\0' && *pattern=='.'))
                return match(str+1, pattern+1);
            else
                return false;
        } else {
            if (*str==*pattern || (*str!='\0' && *pattern=='.'))
                return match(str, pattern+2) || match(str+1, pattern);
            else
                return match(str, pattern+2);
        }
    }
};

// more clear recursion
class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s, p, 0, 0);
    }
private:
    bool match(string &s, string &p, int i, int j)
    {
        if(i == s.size() && j == p.size())
            return true;
        if(j + 1 < p.size() && p[j + 1] == '*')
            return match(s, p, i, j + 2) || (i != s.size() && (s[i] == p[j] || p[j] == '.') && match(s, p, i + 1, j));
        else
            return i != s.size() && j != p.size() && (s[i] == p[j] || p[j] == '.') && match(s, p, i + 1, j + 1);
    }
};