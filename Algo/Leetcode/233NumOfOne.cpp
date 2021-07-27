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