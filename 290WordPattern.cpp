//1.
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream iss(str);
        vector<string> results(istream_iterator<string>{iss},
                                 istream_iterator<string>());
        if(pattern.length()!=results.size())
            return false;
        
        unordered_map<char,int> m;
        unordered_map<string,int> m2;
        
        for(int i=0;i<pattern.length();i++){
            if(m.find(pattern[i])==m.end()){
                m[pattern[i]] = i;
                if(m2.find(results[i])!=m2.end())
                    return false;
                m2[results[i]] = i;
            }else{
                if(results[i]!=results[m[pattern[i]]])
                    return false;
                m[pattern[i]] = i;
            }
        }
        
        return true;
    }
};