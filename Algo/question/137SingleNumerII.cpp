//1. Get each bit's times. retain only %3.
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) { //For which bit
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += (nums[j] >> i) & 1; //The number of bit at i.
            }
            res |= (sum % 3) << i;  //Set the ith bit to 1 if has remainder
        }
        return res;
    }
};

//2. Use one and two to keep.
class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int one = 0, two = 0, three = 0;
            for (auto i : nums) {
                two |= (one & i);         //Which ones are currently twices. Actually two and one&i at bit can not be 1 together.
                one ^= i;                 //which ones are currently one time. ^= return 1 only when one or i is 1. Not both
                three = (one & two);      //Update the threes.
                one &= ~three;             //Update one and two.
                two &= ~three;
            }
        return one;
        }
};