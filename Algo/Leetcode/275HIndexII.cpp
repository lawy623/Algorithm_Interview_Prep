class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l = 0; int r = citations.size()-1;
        int res = 0;
        while(l<=r){
            int m = l+(r-l)/2;
            if(citations[m] >= citations.size()-m){ // You can still go left to find a bigger h index
                res = citations.size()-m;  // it will only increase in future, keep it is correct
                r = m-1;
            }
            else l = m+1;
        }
        return res;
    }
};