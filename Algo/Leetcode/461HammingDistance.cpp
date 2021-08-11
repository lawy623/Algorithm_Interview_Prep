// a^b is the difference of two value. O(1) space and time.
class Solution {
public:
    int hammingDistance(int x, int y) {
        int s = x^y;
        int count = 0;
        for(int i=0; i<32; i++){
            if(s&1<<i) count++;
        }
        return count;
    }
};