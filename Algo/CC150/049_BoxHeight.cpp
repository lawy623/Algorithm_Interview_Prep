// Sort w decending first, then get the max decending array sum in l and h.
int getHeight(vector<int> w, vector<int> l, vector<int> h, int n) {
        for(int i=1;i<n;i++){
            for(int j=i-1; j>=0; j--){
                if (w[j]<w[j+1]){ // decending order
                    swap(w[j], w[j+1]);
                    swap(l[j], l[j+1]);
                    swap(h[j], h[j+1]);
                }
            }
        }
        int* dp = new int[n];
        for(int i=0; i<n; i++)
            dp[i] = h[i];
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++) {
                if (l[i]<l[j])
                    dp[i] = max(dp[i], dp[j]+h[i]);
            }
        }
        int max = 0;
        for(int i=0;i<n;i++){
            if (dp[i]>max)
                max = dp[i];
        }
        return max;
    }
