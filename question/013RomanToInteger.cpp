//1. Iterator through priority. 64ms
class Solution {
public:
    int romanToInt(string s) {
        const vector<int> nums{1000, 900, 500, 400, 100, 90,
                               50, 40, 10, 9, 5, 4, 1};
        const vector<string> romans{"M", "CM", "D", "CD", "C", "XC", "L",
                                    "XL", "X", "IX", "V", "IV", "I"};
        int res = 0;
        int i = 0;
        while(!s.empty()){
            if(s.substr(0,1)==romans[i]){res += nums[i];s = s.substr(1);}
            else if(s.substr(0,2)==romans[i]){res += nums[i];s = s.substr(2);}
            else i++;
        }
        return res;
    }
};


//2.
class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char,int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        
        int sum = m[s[s.size() - 1]];
        
        for(int i = s.size() - 2; i >= 0; i--){
            if(m[s[i]] < m[s[i+1]]){
                sum -= m[s[i]];
            } else{
                sum += m[s[i]];
            }
        }
        return sum;
    }
};