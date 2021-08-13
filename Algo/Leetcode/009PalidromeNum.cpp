//1. Loop forward and create the back one. O(logN)。 152ms.
class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0) return true;
        if(x<0 || x%10 ==0) return false;
        int res = 0;
        int y = x;
        while(y){
            if(res>INT_MAX/10 || res==INT_MAX/10 && y%10>7) return false;
            res = res*10 + y%10;
            y /= 10;
        }
        return res == x;
    }
};

//2.Actually can half the while loop. O(logN / 2). 144ms.
class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0) return true;
        if(x<0 || x%10 ==0) return false;
        int res = 0;

        while(x > res){
            if(res>INT_MAX/10 || res==INT_MAX/10 && x%10>7) return false;
            res = res*10 + x%10;
            x /= 10;
        }
        return res == x || x==res/10;
    }