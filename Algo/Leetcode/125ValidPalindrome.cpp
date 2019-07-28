//1. Use tolower transformation / isalnum decision. O(N)
class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();
        transform(s.begin(),s.end(),s.begin(),::tolower);
        
        auto left = s.begin(), right = s.end()-1;
        while(left<right){
            if(!isalnum(*left)) ++left;
            else if(!isalnum(*right)) --right;
            else if( (*left)!=(*right) ) return false;
            else{left++;right--;}
        }
        return true;
    }
};