//Actually this is calculating a fabonacci number.
//1. Recursion
class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        
        return (climbStairs(n-1) + climbStairs(n-2));
    }
};

//2. Iteration
class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> res;
        for(int i=0;i<n;i++){
            if(i==0) {res.push_back(1);}
            else if(i==1) {res.push_back(2);}
            else res.push_back(res[i-1] + res[i-2]);
        }
        return res[n-1];
    }
};

//or 
class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            if(i==0) {res[0] = 1;}
            else if(i==1) {res[1] = 2;}
            else res[i] = (res[i-1] + res[i-2]);
        }
        return res[n-1];
    }
};