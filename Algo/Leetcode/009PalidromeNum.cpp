//1. Loop forward and create the back one. O(logN)。 152ms.
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0) ) return false;  //Can not have last digit as 0;
        if(x==0) return true;
        
        int rev = 0;
        int y = x;
        while(y){
            rev = rev * 10 + y % 10;
            y = y/10;
        }
        
        cout << rev;
        return rev == x;
    }
};

//2.Actually can half the while loop. O(logN / 2). 144ms.
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0) )  return false;
        if(x==0) return true;
        
        int rev = 0;
        
        while(x>rev){
            rev = rev * 10 + x % 10;
            x = x/10;
        }
        
        return (x==rev || x==rev/10);
    }
};