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
        unordered_set<int> used;
        
        for(auto i : nums) used.emplace(i);
        
        int longest = 0;
        
        while(!used.empty()){
            auto num = *used.begin();
            used.erase(num);
            
            int length = 1;

            int num2 = num;
            while(used.count(++num)) {used.erase(num);length++;}
            while(used.count(--num2)) {used.erase(num2);length++;}
            
            if(length>longest) longest = length;
        }
        
        return longest;
    }
};