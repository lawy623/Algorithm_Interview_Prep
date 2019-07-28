// a sorting. require O(nlogn) time. Need to prove this is correct.
class Solution {
public:
    static bool comp(int a, int b) {
        string A = to_string(a);
        A.append(to_string(b));
        string B = to_string(b);
        B.append(to_string(a));
        return A<B;
    }
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), comp);
        string res = "";
        for(auto x : numbers){
             res.append(to_string(x));
         }
        return res;
    }
};
