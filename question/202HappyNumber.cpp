//1. Actually this program is a loop problem. O(1) space.
class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast =n;
        while(true){
            slow = getSum(slow);
            fast = getSum(fast);
            fast = getSum(fast);
            
            if(fast == 1 || slow == 1) return true;
            else if(slow == fast) return false;
        }
    }
    
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += pow(n%10,2);
            n /= 10;
        }
        return sum;
    }       
};

//2. Use a set to keep track the existing results. Avoid unlimited loop.
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> all;
        while(n!=1){
            n = getSum(n);
            if( all.count(n) >0 ) return false;
            else all.insert(n);
        }
        return true;
    }
    
    int getSum(int n){
        int sum = 0;
        while(n){
            sum += pow(n%10,2);
            n /= 10;
        }
        return sum;
    }       
};