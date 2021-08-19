// bucket sort
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int max_c = 0;
        for(auto n : citations) max_c = max(max_c, n);

        vector<int> bucket(max_c + 1);
        for(auto n : citations) bucket[n]++;

        int hVal = 0;
        int count = 0;
        for(int i=max_c; i>=0; i--){
            count += bucket[i];
            if(count >= i) hVal = max(hVal, i);
        }
        return hVal;
    }
};

// sort and find
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        for(int i=0; i<citations.size(); i++){
            if(citations.size() - i <= citations[i]) return citations.size() - i;
        }
        return 0;
    }
};