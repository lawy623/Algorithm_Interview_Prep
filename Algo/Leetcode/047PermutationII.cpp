//1. Similar to permutation. But use a set to remove duplicates.
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        if(nums.size()==1){
            res.push_back(nums);
            return res;
        }
        sort(nums.begin(),nums.end());
        
        set<vector<int>> tmp;
        int d = nums[0];
        vector<int> lastV(nums.begin()+1,nums.end());
        res = permuteUnique(lastV);
        int len = res.size();
        for(int i=0;i<len;i++){
            for(int j=0;j<res[0].size()+1;j++){
                    vector<int> v = res[0];
                    v.insert(v.begin()+j,d);
                    tmp.insert(v);
            }
            res.erase(res.begin());
        }
        copy(tmp.begin(),tmp.end(),back_inserter(res));
        return res; 
    }
};

//2.DFS
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        if(nums.size()==1){
            res.push_back(nums);
            return res;
        }
        sort(nums.begin(),nums.end());
        
        unordered_map<int,int> count_map;
        for_each(nums.begin(),nums.end(),[&count_map](int e){
            if(count_map.find(e) != count_map.end()) count_map[e]++;
            else count_map[e] = 1;
        });
        
        vector<pair<int,int> > elems;
        for_each(count_map.begin(),count_map.end(),[&elems](const pair<int,int> &e){
            elems.push_back(e);
        });
        
        vector<vector<int>> result;
        vector<int> p;
        
        n = nums.size();
        permute(elems.begin(),elems.end(),p,result);
        return result;
    }
    
private:
    int n;
    typedef vector<pair<int,int>>::const_iterator Iter;
    
    void permute(Iter first, Iter last, vector<int> &p, vector<vector<int>> &result){
        if(n==p.size()){result.push_back(p);}
        
        for(auto i=first;i!=last;i++){
            int count = 0;
            for(auto j=p.begin();j!=p.end();j++){
                if(i->first == *j){
                    count++;
                }
            }
            if(count<i->second){
                p.push_back(i->first);
                permute(first,last,p,result);
                p.pop_back();
            }
        }
    }
};

// better dfs
class Solution {
public:
    vector<vector<int> > res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }

    void dfs(vector<int>& nums, int x){
        if (x==nums.size()-1)
            res.push_back(nums);

        set<int> st;
        for(int i=x; i<nums.size(); i++){
            if(st.find(nums[i]) != st.end()) continue;
            st.insert(nums[i]);
            swap(nums[i], nums[x]);
            dfs(nums, x+1);
            swap(nums[i], nums[x]);
        }
    }
};