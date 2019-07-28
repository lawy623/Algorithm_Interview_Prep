//1.Recursion. Keep a full n-length string. Remove from it. 
class Solution {
public:
    string getPermutation(int n, int k) {
        string nums = "123456789";
        return getPermutation(nums.substr(0,n),n,k);
    }
    
    string getPermutation(string s,int n, int k){
        if(n==1 && k==1) return s;
        
        int times = (k-1) / calPer(n-1);
        char head = s[times];
        s.erase(s.begin()+times);
        return head + getPermutation(s,n-1, k - times*calPer(n-1));
    }
    
    int calPer(int n){
        if(n==1) return 1;
        return n*calPer(n-1);
    }
};


//Get it in one for loop
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string nums = "123456789";
        for (int i = n; i >= 1; --i) {
            int j = (k-1) / calPer(i-1);
            k -= j*calPer(i-1);
            res.push_back(nums[j]);
            nums.erase(j,1);
        }
        return res;
    }
    
    int calPer(int n){
        if(n==0) return 1;
        return n*calPer(n-1);
    }
};