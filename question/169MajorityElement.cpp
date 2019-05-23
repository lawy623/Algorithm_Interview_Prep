//1. Use a map to store the num of appearance, O(N)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            auto f = m.find(nums[i]);
            if(f!=m.end()) f->second += 1;
            else m.insert(make_pair(nums[i],1));
        }
        for(auto i=m.begin();i!=m.end();i++){
            if(i -> second > nums.size()/2) return i->first;
        }
        return NULL;
    }
};

//2. Sort the array. The majority must at n/2. O(NlogN)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        return nums[ nums.size()/2 ];
    }
};

//3. Boyer-Moore Algorithm. O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count = 0;
        int candidate = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};

//4. Use bit manupilation. Find 1's or 0's at each postion.
class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count1=0, count0= 0;
        int res = 0;
        
        for(int i=0;i<32;i++){
            for(int j=0;j<nums.size();j++){
                int one = (nums[j]>>i & 1);
                if(one) count1++;
                else count0++;
            }
            if(count1>count0) res+= 1<<i;
            count0 =0; 
            count1 =0;    
        }
        return res;
    }
};