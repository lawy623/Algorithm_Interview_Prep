// greedy
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0] > b[0]) return true;
        if(a[0] == b[0]) return a[1] < b[1];
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);

        vector<vector<int>> res;
        for(int i=0; i<people.size(); i++){
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};

// with list it become faster
class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0] > b[0]) return true;
        if(a[0] == b[0]) return a[1] < b[1];
        return false;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);

        list<vector<int>> res;
        for(int i=0; i<people.size(); i++){
            list<vector<int>>::iterator it = res.begin();
            int k = people[i][1];
            while(k>0) {it++;k--;}
            res.insert(it, people[i]);
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};