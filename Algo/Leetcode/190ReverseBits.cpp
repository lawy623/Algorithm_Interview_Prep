//1. Get last bit. Move to front and add to result.
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(auto i=0;i<32;i++){
            uint32_t last = n>>i & 1;
            res += last<<(31-i);
        }
        return res;
    }
};