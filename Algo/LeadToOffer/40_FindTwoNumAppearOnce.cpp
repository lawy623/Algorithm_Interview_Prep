//1. XOR and seperate the array by different bit.
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int xor_v = 0;
        for (int i = 0; i < data.size(); i++) {
            xor_v ^= data[i];
        }
        int shift = 0;
        for (int i=0; i<32; i++) {
            if (xor_v & 1<<i)
                shift = i;
        }
        // find first
        xor_v = 0;
        for (int i = 0; i < data.size(); i++) {
            if (data[i] & 1<<shift)
                xor_v ^= data[i];
        }
        *num1 = xor_v;
        //find second
        xor_v = 0;
        for (int i = 0; i < data.size(); i++) {
            if (! (data[i] & 1<<shift) )
                xor_v ^= data[i];
        }
        *num2 = xor_v;
        return;
    }
};


// extent for （1，3，3，3）case
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int r = 0;
        for(int i=0; i<32; i++){
            int sum = 0;
            for(int n:nums){
                if(n&(1<<i)) sum++;
            }
            if(sum%3) r = r | (1<<i); //3 here can be extended to all other n
        }
        return r;
    }
};