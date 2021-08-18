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

// based on factorization result
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fac(n+1, 1);
        for(int i=1; i<=n; i++){
            fac[i] = fac[i-1] * i;
        }

        k--;

        string res = "";
        vector<int> valid(n+1, 1);
        for(int i=n; i>=1; i--){
            int order = k / fac[i-1] + 1;   // first element in this pos
            for(int j=1; j<=n; j++){
                order -= valid[j];
                if(order==0){               // adding the order-th biggest num in remaining
                    res += (j + '0');
                    valid[j] = 0;
                    break;
                }
            }
            k = k % fac[i-1];              // remaining k for the res of nums
        }

        return res;
    }
};