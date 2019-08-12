// Add each subsection of rows and find max_sub_array
class SubMatrix {
public:
    int sumOfSubArray(vector<int> arr, int n) {
        int max_sum = arr[0];
        int res = max_sum;
        for(int i=1; i<n; i++) {
            if (max_sum<=0)
                max_sum = arr[i];
            else
                max_sum += arr[i];
            res = max(max_sum, res);
        }
        return res;
    }
    int sumOfSubMatrix(vector<vector<int> > mat, int n) {
        int max_sum = INT_MIN;
        for(int i=0; i<n; i++) {
            vector<int> row(mat[i]);
            max_sum = max(max_sum, sumOfSubArray(row, n));
            for(int j=i+1; j<n; j++) {
                for(int k=0; k<n; k++) {
                    row[k] += mat[j][k];
                }
                max_sum = max(max_sum, sumOfSubArray(row, n));
            }
        }
        return max_sum;
    }
};
