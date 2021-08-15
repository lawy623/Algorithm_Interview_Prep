//1.Brute Force   76ms O(N^2) Time, O(1) Space
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> result;
        if(nums.size()<=1)  return result; //Good edge check here.
        
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                int res = target - nums[i];
                if(nums[j] == res){
                    result.push_back(i);
                    result.push_back(j); 
                    return result;
                }
            }
        }
        
    }
};

//2. Use Hash Table. Store num as Key and ind as value. Find is O(1).
//.  Overall Time is O(n). Space is O(n).
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> result;
        if(nums.size()<=1){
            return result;
        }
        map<int,int> res;
        for(int i=0;i<len;i++){ 
            res.insert(pair<int,int>(nums[i],i));
            map<int,int>::iterator pos = res.find(target-nums[i]);
            if(pos!=res.end()&&pos->second!=i){ //!=i here is important to avoid double counting
                result.push_back(pos->second);
                result.push_back(i);
                return result;
            }
        }
        //如果用先将所有的保存到hash中一次在检查，记得要判断index的大小。相同舍去，否则小的放前面
    }
};
/*先查找，后添加*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        int n = nums.size();
        if(n<=1) return {};
        m[nums[0]] = 0;
        for(int i=1; i<n; i++){
            if(m.find(target-nums[i])!=m.end()){
                return {m[target-nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};

//用unordered_map花费8ms。查找更慢
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < nums.size(); ++i) {
            if (lookup.count(target - nums[i])) {
                return {lookup[target - nums[i]], i};
            }
            lookup[nums[i]] = i;  
        }
        return {};
    }
};


//3. Sort First. Use O(n) to find sorted index. Use O(n) to find back index. O(n) Space
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> backup(nums);
        vector<int> res;
        sort(nums.begin(),nums.end());
        
        int left = 0, right = nums.size() - 1;
        while (left != right) {
            const auto sum = nums[left] + nums[right];
            if (sum > target) {
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                for(int i=0;i<nums.size();i++){
                    if(nums[left]==backup[i]) {res.push_back(i);}
                    if(nums[right]==backup[i]&&nums[left]!=backup[i]) res.push_back(i); //Make sure will not use the same one.                }
                sort(res.begin(),res.end());  //If the result require the order
                return res;
            }
        }
        return {0, 0};  //Always return corner case.
    }
};