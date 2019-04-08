//Run one through.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int total = 0;
        int j = -1;
        for(int i=0;i<gas.size();i++){
            sum += gas[i] - cost[i];
            total += gas[i]-cost[i];
            if(sum<0){
                sum = 0;
                j=i;
            }
        }
        
        return total>=0? j+1:-1;
    }
};