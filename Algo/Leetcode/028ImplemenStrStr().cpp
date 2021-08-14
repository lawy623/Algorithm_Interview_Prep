//1. Brute Force. O(m*n).
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if(m==0) return 0;
        if(n==0 || n<m) return -1;
        for(int i=0; i<n-m+1; i++){
            if(haystack[i]==needle[0]){
                int j = 1;
                while(j<m && needle[j]==haystack[i+j]) j++;
                if(j==m) return i;
            }
        }
        return -1;
    }
};

//2. Use kmp.
// Not Now, learn it when free.