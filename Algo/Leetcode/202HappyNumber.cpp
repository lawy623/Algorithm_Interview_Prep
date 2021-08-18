//1. Actually this program is a loop problem. O(1) space.
// Once any num becomes one, it will not change anymore
class Solution {
public:
    bool isHappy(int n) {
        int slow = n; int fast = n;
        do{
            fast = calSquareSum(fast);
            fast = calSquareSum(fast);
            slow = calSquareSum(slow);
        } while(fast != slow);
        return slow == 1;
    }

    int calSquareSum(int n){
        int res = 0;
        while(n){
            res += (n%10) * (n%10);
            n /= 10;
        }
        return res;
    }
};

//2. Use a set to keep track the existing results. Avoid unlimited loop.
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(n != 1){
            if(s.find(n) != s.end()) return false;
            s.insert(n);
            n = calSquareSum(n);
        }
        return true;
    }

    int calSquareSum(int n){
        int res = 0;
        while(n){
            res += (n%10) * (n%10);
            n /= 10;
        }
        return res;
    }
};