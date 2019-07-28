//1.Brute Force.  Slow O(n^3) Time. Check each substring is unique by Map/Set. 
//O(min(m,n)) Space, where m is the size of charset(Max num of char in string)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int len = s.length();
        if(len<=1) return len;
        for(int i=0; i<len; i++){                                  //One Loop
            for(int j=i; j<len; j++){                              //Second Loop
                if(checkAllUnique(s,i,j)) ans = max(ans,j-i+1);    //Third Loop.   In total O(n^3)
            }
        }
        
        return ans;
    }
    bool checkAllUnique(string s, int start, int end){  //For each j-i size substring. Check is j-i.
            map<char,int> temp;
            for(int i=start;i<=end;i++){
                if(temp.find(s[i])!=temp.end()){return false;}
                temp.insert(pair<char,int>(s[i],i));
            }
            return true;            
        }      
/*此处用set也可以，o（logn）查找时间,理论上为o（1）。（set为红黑树/平衡二叉树）
                bool checkAllUnique(string s, int start, int end){
                    set<char> temp;
                    for(int i=start;i<=end;i++){
                        if(temp.find(s[i])!=temp.end()){return false;}
                        temp.insert(s[i]);
                    }
                    return true;            
                } 
*/
};

//2.Sliding Windows. Keep moving the head and back of the substring. Put in set/map. If not exist,
// move back forward. Else, move front forward until not exist. O(n).

//Use Set 28ms.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        set<char> Cset;
        int ans = 0, i =0, j=0;
        while(i<n && j<n){
            if(!Cset.count(s[j])){
                Cset.insert(s[j++]);
                ans = max(ans,j-i);
            }
            else{
                Cset.erase(s[i++]);
            }
        }
        return ans;
    }
};
//Use Map 32ms.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char,int> Cmap;
        int ans = 0, i =0, j=0;
        while(i<n && j<n){
            if(!Cmap.count(s[j])){
                Cmap.insert(pair<char,int>(s[j++],j));
                ans = max(ans,j-i);
            }
            else{
                Cmap.erase(s[i++]);
            }
        }
        return ans;
    }
};
//3.improvement on Map in 2. Keep value as the index, directly move i to the exist one.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<char,int> Cmap;
        int ans = 0, i = 0;
        for(int j=0; j<n; j++){
            if(Cmap.find(s[j])!=Cmap.end()){
                i = max(Cmap.at(s[j])+1,i);
                Cmap.erase(s[j]);
            } 
                Cmap.insert(pair<char,int>(s[j],j));
                ans = max(ans, j-i+1);   
        }        
        return ans;
    } 
};

//Use 256 array to store pos of the chars.  12ms
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }