// Contiue sum using two pointer. O(n) time, O(1) space.
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        if (sum<3)
            return res;
        int low = 1;
        int high = 2;
        int sum_seq = 0;
        while(low<(sum+1)/2) {
            if (low==high)
                high++;
            sum_seq = (low+high)*(high-low+1)/2;
            if (sum_seq==sum) {
                vector<int> seq;
                for (int i=low; i<=high; i++)
                    seq.push_back(i);
                res.push_back(seq);
                high++;
            } else if (sum_seq<sum) {
                high++;
            } else {
                low++;
            }
        }
        return res;
    }
};
