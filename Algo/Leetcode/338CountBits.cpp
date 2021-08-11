// O(N*sizeof(bit)) time
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0; i<=n; i++){
            res.push_back(countOne(i));
        }
        return res;
    }

    int countOne(int n){
        int sum = 0;
        for(int i=0; i<32; i++){
            sum += (n>>i & 1);
        }
        return sum;
    }
};

// O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        res[0] = 0;
        for(int i=1; i<=n; i++){
            if(i%2==1) res[i] = res[i-1] + 1;  // odd num, must be one bit more than last
            else res[i] = res[i/2];            // even num, must be same as i/2
        }
        return res;
    }
};