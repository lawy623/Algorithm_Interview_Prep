// dp. Use two array to store min and max
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        vector<int> min_v(n);
        vector<int> max_v(n);
        min_v[0] = prices[0];
        max_v[0] = prices[n-1];
        for(int i=1; i<n; i++){
            min_v[i] = min(min_v[i-1], prices[i]);
            max_v[i] = max(max_v[i-1], prices[n-i-1]);
        }

        int max_profit = 0;
        for(int i=0; i<n; i++){
            max_profit = max(max_profit, max_v[n-i-1] - min_v[i]);
        }
        return max_profit;
    }
};

// Just store the lowest price and get largest profit
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1) return 0;
        int min_v = INT_MAX;
        int max_profit = 0;
        for(int i=0; i<n; i++){
            min_v = min(min_v, prices[i]);
            max_profit = max(max_profit, prices[i] - min_v);
        }

        return max_profit;
    }
};