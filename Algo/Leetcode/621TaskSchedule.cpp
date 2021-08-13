// greedy
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> m;
        for(char c:tasks) m[c]++;

        int max_n = 0;
        int count = 0;
        for(auto it=m.begin(); it!=m.end(); it++){
            if(it->second > max_n){
                max_n = it->second;
                count = 1;
            } else if(it->second == max_n){
                count++;
            }
        }

        int k = tasks.size();
        return max(k, (max_n-1)*(n+1) + count);
    }
};