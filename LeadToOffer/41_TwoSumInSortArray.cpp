// 1. two sum. Return the min prod result.
// Two pointer. O(n) time.
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        int prod = INT_MAX;
        if (array.size()==0)
            return res;

        int i = 0, j = array.size()-1;
        while(i<j) {
            if (array[i]+array[j]==sum){
                if (array[i]*array[j]<prod) {
                    res.clear();
                    res.push_back(array[i]);
                    res.push_back(array[j]);
                    prod = array[i]*array[j];
                }
                if (array[i+1]==array[i])
                    i++;
                else if (array[j-1]==array[j])
                    j--;
                else {
                    i++;j--;
                }
            }
            else if (array[i]+array[j]>sum)
                j--;
            else
                i++;
        }
        return res;
    }
};
