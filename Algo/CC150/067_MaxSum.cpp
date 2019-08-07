class MaxSum {
public:
    int getMaxSum(vector<int> A, int n) {
        int sum = A[0];
        int max_sum = sum;
        for(int i=1; i<n; i++) {
            if (sum<=0)
                sum = A[i];
            else
                sum += A[i];
            if (sum>max_sum)
                max_sum = sum;
        }
        return max_sum;
    }
};
