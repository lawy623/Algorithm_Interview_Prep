// 1. logical question. O(1) time O(1) space.
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if (numbers.size()!=5)
            return false;

        sort(numbers.begin(), numbers.end());
        if (numbers[0]<0 || numbers[4]>13) return false;

        int count_zeros = 0;
        for(int i=0; i<5; i++) {
            if (numbers[i]==0)
                count_zeros ++;
        }
        if (count_zeros>4) return false;
        if (count_zeros==4) return true;

        for (int i=count_zeros; i<4; i++) {
            if (numbers[i]==numbers[i+1])
                return false;
        }
        if (numbers[4] - numbers[count_zeros]<=4)
            return true;
        return false;
    }
};
