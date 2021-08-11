// O(n*sqrt(n)) time. Each check whether is prime
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for(int i=2; i<n; i++){
            if(isPrime(i)) count++;
        }
        return count;
    }

    bool isPrime(int n){
        for(int i=2; i*i<=n; i++){ //from 2~sqrt(n), check remaining part.
            if(n % i==0) return false;
        }
        return true;
    }
};

// O(nloglogn) time, O(n) space
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector<bool> isPrime(n, true);
        for(int i=2; i*i<=n; i++){
            if(isPrime[i]){
                for(int j=i*i; j<n; j+=i)
                    isPrime[j] = false;
            }
        }

        for(int i=2; i<n; i++)
            count += isPrime[i];

        return count;
    }
};