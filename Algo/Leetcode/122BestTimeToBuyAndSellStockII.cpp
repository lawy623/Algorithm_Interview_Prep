// Calculate profit between every two days
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_v = 0;
        for(int i=1; i<prices.size();i++){
            max_v += max(0, prices[i] - prices[i-1]);
        }
        return max_v;
    }
};