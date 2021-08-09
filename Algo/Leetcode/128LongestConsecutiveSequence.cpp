//1. Use map. Remember to record the true/false.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> used;
        
        for(auto i : nums) used[i] = false;
        
        int longest = 0;
        
        for(auto i : nums){
            if(used[i]) continue;
            
            int length = 1;
            
            used[i] = true;
            int j =i;
            while(used.find(++i)!= used.end()) {used[i]=true;length++;}
            while(used.find(--j)!= used.end()) {used[j]=true;length++;}
            
            if(length>longest) longest = length;
        }
        
        return longest;
    }
};


//2.Use Set. O(N). This is more intuitively to modify the set.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return n;
        set<int> m;
        int max_len = 1;
        for(auto a:nums) m.insert(a);
        for(auto a:nums){
            if(m.find(a+1)==m.end()){ // if not this, will go to O(n^2) for strictly decreasing case
                int l = 0;
                int target = a;
                while(m.find(target) != m.end()){
                    l++;
                    target -= 1;
                }
                max_len = max(max_len, l);
            }
        }
        return max_len;
    }
};