//1. Brute Force. O(m*n).
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1 = haystack.length();
        int n2 = needle.length();
        if(n2==0) return false;
        
        int i=0;
        while(i+n2<=n1){
            if(haystack[i]!=needle[0]){
                i++;
                continue;
            }
            int j=1;
            bool find = true;
            while(j<n2){
                if(haystack[i+j]!=needle[j]){
                    find = false;
                    break;
                }
                j++;
            }
            if(find) return i;
            else{i+=1;}
        }
        return -1;
    }
};

//2. Use kmp.