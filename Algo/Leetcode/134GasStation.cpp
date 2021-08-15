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

// more detail to understand
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;
        while(i < n){               // start from every i
            int sumGas = 0;
            int sumCost = 0;
            int count = 0;
            while(count < n){        // if count == n, satisfied
                int j = (i + count) % n;
                sumGas += gas[j];
                sumCost += cost[j];
                if(sumCost > sumGas) break;   // at any point, gas if not enough for cost
                count++;
            }
            if(count == n){
                return i;
            } else {
                i = i + count + 1;             // if you can not go from i to j, you can not go from any point in (i,j) to j. You must start from new point
            }
        }
        return -1;
    }
};