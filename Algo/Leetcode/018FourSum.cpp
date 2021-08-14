//1.Same as three. O(N^3)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n<=3) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-3; i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j=i+1; j<n-2; j++) {
                if(j>i+1 && nums[j] == nums[j-1]) continue;{
                    for(int k=j+1, p=n-1; k<p;) {
                        if(k>j+1 && nums[k]==nums[k-1]) k++;
                        else if(p<n-1 && nums[p]==nums[p+1]) p--;
                        else{
                            long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[p];  // leetcode is crazy
                            if(sum==target) res.push_back({nums[i],nums[j],nums[k++],nums[p--]});
                            else if(sum>target) p--;
                            else k++;
                        }
                    }
                }
            }
        }
        return res;
    }
};

//2. Save pair sums into unordered_multimap. Then do two sum. O(N^2).
class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> result;
            if (nums.size() < 4) return result;
            sort(nums.begin(), nums.end());
            unordered_multimap<int, pair<int, int>> cache;  //Keep sum as index, pair<int,int> as value. Allow multi value./
            for (int i = 0; i + 1 < nums.size(); ++i)
                for (int j = i + 1; j < nums.size(); ++j)
                    cache.insert(make_pair(nums[i] + nums[j], make_pair(i, j))); //Else can use insert(pair<int,int>(3,4)) likewise to insert. 
            
            for (auto i = cache.begin(); i != cache.end(); ++i) {
                int x = target - i->first;
                auto range = cache.equal_range(x);  //Here it can find the index with multiple value.
                for (auto j = range.first; j != range.second; ++j) { //Range is actually iterator. Here is not begin/end. But First and Second.
                    auto a = i->second.first;
                    auto b = i->second.second;
                    auto c = j->second.first;
                    auto d = j->second.second;
                    if (a != c && a != d && b != c && b != d) {.  //Indexs not equal means that no re-usage of the numbers.
                        vector<int> vec = { nums[a], nums[b], nums[c], nums[d] };
                        sort(vec.begin(), vec.end());
                        result.push_back(vec);
                    }
                }
            }
            sort(result.begin(), result.end());
            result.erase(unique(result.begin(), result.end()), result.end());
            return result;
        }
};