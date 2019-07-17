// 1. Use map. Store the first position. O(n) time, O(1) space.
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.length()==0)
            return -1;
        unordered_map<char, int> dict;
        for (int i=0; i<str.length(); i++) {
            if (dict.find(str[i])==dict.end())
                dict[str[i]]=i;
            else
                dict[str[i]]=-1;
        }
        unordered_map<char,int>::iterator iter;
        int min_pos = INT_MAX;
        for (iter=dict.begin(); iter!=dict.end(); iter++) {
            if (iter->second != -1 && iter->second<min_pos)
                min_pos = iter->second;
        }
        return min_pos<INT_MAX?min_pos:-1;
    }
};

// 2. Use array as map to store at most 256 char.
// The value at pos is the appreance time. O(1) space, O(n) time.
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if (str.length()==0)
            return -1;
        unsigned int table[256];
        for (int i=0; i<256; i++) {
            table[i]=0;
        }
        for (int i=0; i<str.length(); i++) {
            table[int(str[i])]++;
        }
        for (int i=0; i<str.length(); i++) {
            if (table[int(str[i])]==1)
                return i;
        }
        return -1;
    }
};
