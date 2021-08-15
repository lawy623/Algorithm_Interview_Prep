class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for(long long i=1; i<=n; i*=10){
            long long div = i * 10;
            count += (n / div) * i + min(max(n % div - i + 1, 0LL), i);
        }
        return count;
    }
};

// brute force
class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for(int i=1; i<=n; i++)
            count += countOne(i);
        return count;
    }

    int countOne(int i){
        string s = to_string(i);
        int count = 0;
        for(auto c : s) count+= (c=='1');
        return count;
    }
};

//
class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        int a, b = 0;
        for(long m=1; m<=n; m*=10){
            a = n/m;
            b = n%m;
            count += (a+8)/10*m + (a%10==1)*(b+1);
            // count is for the 1 at each position.
            // (a+8)/10*m is by counting the before number from 0.
            // (a%10==1)*(b+1) is for counting the smaller fraction
        }
        return count;
    }
};