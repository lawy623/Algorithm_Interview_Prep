//1. One for loop to add. O(N)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;        
        for(int i=digits.size()-1;i>=0;i--){
            if(carry==0) break;
            int sum = digits[i]+carry;
            digits[i] = sum%10;
            carry = sum/10;
        }
        if(carry) digits.insert(digits.begin(),1);  //Vector can also insert in the front.
        
        return digits;
    }
};