//1. like dp. O(n) time, O(n) space.
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size()==0)
            return 0;

        vector<int> sum;
        sum.push_back(array[0]);
        for (int i = 1; i < array.size(); i++) {
            if (sum.back()<0)
                sum.push_back(array[i]);
            else
                sum.push_back(sum.back()+array[i]);
        }

        return *max_element(sum.begin(), sum.end());
    }
};

//2. same logic. But O(1) space, O(n) time.
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size()==0)
            return 0;

        int sum = 0;
        int res = INT_MIN;
        for (int i = 0; i < array.size(); i++) {
            if (sum<=0)
                sum = array[i];
            else
                sum += array[i];

            if (sum > res)
                res = sum;
        }

        return res;
    }
};
