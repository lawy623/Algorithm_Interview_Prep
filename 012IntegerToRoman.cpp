class Solution {
public:
    string intToRoman(int num) {
        vector<int> nums = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> romans = {"M", "CM", "D", "CD", "C", "XC", "L",
                         "XL", "X", "IX", "V", "IV", "I"};
        string res ="";
        int i = 0;
        while(num>0){
            int time = num / nums[i];
            num -= nums[i]*time;
            while(time--){
                res += romans[i];
            }
            i++;
        }
        return res;
    }    
};