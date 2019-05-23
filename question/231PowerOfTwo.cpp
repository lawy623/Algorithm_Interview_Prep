//1. Use a for loop.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int sum = 0;
        for(int i=0; i<31; i++){
            sum += n>>i & 1;
        }
        
        return (sum==1) && n>0;
    }
};

//2. One Step calculation.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n<=0) return false;
        
        return ( (n & (n-1)) ==0? true:false );
    }
};