// count the 1's num at each pos. Difference at each pos is c * (n-c)
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int count = 0;
        for(int i=0; i<32; i++){
            int c = 0;
            for(auto n:nums) c += (n>>i) & 1;
            count += c * (nums.size() - c);
        }
        return count;
    }
};