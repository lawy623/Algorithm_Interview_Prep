//Find the relation. Turn last array to next. o(2^N)
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        
        int i=0;
        while(i<=n){
            if(i == 0) {res.push_back(0);}
            else grayC(res,i);
            i++;
        }
        return res;
    }
    
    void grayC(vector<int>& last, int n){
            bool dir = true;
            for(int i=0; i < pow(2,n); i++){
                int add = 0;
                if(i%2==0 && dir || i%2==1 && !dir) add=0;
                else add = 1;
                int newNum = last[0]*2 + add;
                last.push_back(newNum);
                if(i%2==1) {dir = !dir;last.erase(last.begin());}
            }
    }
};

//2. Use bit manupilation. Same idea.
class Solution {
    public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.reserve(1<<n);
        result.push_back(0);
        for (int i = 0; i < n; i++) {
            const int highest_bit = 1 << i;
            for (int j = result.size() - 1; j >= 0; j--)
                result.push_back(highest_bit | result[j]);
            }
        return result;
    }
};

//3. Use formula i ^ i/2. (^ is or operation)
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i=0;i< 1<<n ;i++)
            res.push_back(i ^ i/2);
        return res;
    }
};