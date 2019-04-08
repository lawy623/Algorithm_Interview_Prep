//1, Just ignore the new part if duplicated num get out again. 
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.size()==0) {
            res.push_back({});
            return res;
        }
        else if(nums.size()==1){
            res.push_back({});
            res.push_back({nums[0]});
            return res;
        }
        else{
            int n = nums[nums.size()-1];
            int n_1 = nums[nums.size()-2];
            vector<int> subvector(nums.begin(),nums.end()-1);
            vector<int> subvector2(nums.begin(),nums.end()-2);   //Consume too much memory.
            vector<vector<int>> res  = subsetsWithDup(subvector);
            vector<vector<int>> res2  = subsetsWithDup(subvector2);
            int len = res.size();
            int i = (n==n_1)? res2.size() : 0;   //Get the newly generated part from n-1.
            for(;i<len;i++){
                vector<int> temp = res[i];
                temp.push_back(n);
                res.push_back(temp);    
            }
            return res;                      
        }
    }
};

//More concise version
class Solution {
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            sort(S.begin(), S.end());   //Sort here is important.
            vector<vector<int> > result(1);  //Here now result is {[]}.
            size_t previous_size = 0;
            for (size_t i = 0; i < S.size(); ++i) {
                const size_t size = result.size();
                for (size_t j = 0; j < size; ++j) {
                    if (i == 0 || S[i] != S[i-1] || j >= previous_size) {
                        result.push_back(result[j]);
                        result.back().push_back(S[i]);
                    }
                }
                previous_size = size;  //Previous size is the size before expansion for S[i].
            }
        return result;
        }
};


//2. Use bit map. And a set to remove duplicates.v Actually it take O(n) space.
class Solution {
    public:
        vector<vector<int>> subsetsWithDup(vector<int> &S) {
            sort(S.begin(),S.end());
            set<vector<int>> result;
            int n = S.size();
            vector<int> v;
            
            for(int i=0;i< 1<<n;i++){
                for(int j=0;j<n;j++){
                    if( i>>j & 1) v.push_back(S[j]);
                }
                result.insert(v);
                v.clear();
            }
            
            vector<vector<int>> res;
            //for(auto i=result.begin();i!=result.end();i++) res.push_back(*i);
            copy(result.begin(), result.end(), back_inserter(real_result));
            return res;
        }
};