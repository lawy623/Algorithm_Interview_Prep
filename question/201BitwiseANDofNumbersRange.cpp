//1. Use for loop. Out of Bound time.
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = m;
        for(int i=m+1;i<=n;i++){
            res &= i;
        }
        return res;
    }
};

//2. Know that this should only return the left side equal nums.
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while(m!=n){
            m >>= 1;
            n >>= 1;
            i +=1;
        }
        
        return m<<i;
    }
};