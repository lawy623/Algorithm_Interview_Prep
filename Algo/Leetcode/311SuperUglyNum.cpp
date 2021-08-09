// O(mn)
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> res;
        res.push_back(1);
        vector<int> pos(primes.size(), 0);
        while(res.size() < n){
            int next_val = INT_MAX;
            for(int i=0; i<pos.size(); i++){
                if(res[pos[i]]*primes[i] < next_val )
                    next_val = res[pos[i]]*primes[i];
            }
            res.push_back(next_val);
            for(int i=0; i<pos.size(); i++){
                if(res[pos[i]]*primes[i] == next_val) pos[i]++;
            }

        }
        return res[n-1];
    }
};