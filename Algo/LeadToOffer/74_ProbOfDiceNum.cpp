// dp. O(n) space, O(n^2) time.
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> prob(6, 1.0/6.0);
        if(n==1) return prob;

        for(int i=2; i<=n; i++){
            vector<double> tmp(5*i+1); // From i~6i
            for(int k=0; k<prob.size(); k++){
                for(int p=0; p<6; p++){
                    tmp[p+k] += prob[k] / 6.0;
                }
            }
            prob = tmp;
        }
        return prob;

    }
};