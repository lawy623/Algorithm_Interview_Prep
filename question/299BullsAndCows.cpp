//1.Hash Table
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        if(n==0)
            return "0A0B";
        
        int bulls = 0;
        int cows = 0;
        
        string g = "";
        unordered_map<char,int> m;
        for(int i=0; i<n; i++){
            if(secret[i]==guess[i]){
                bulls++;
            }else{
                g += guess[i];
                if(m.find(secret[i])!=m.end()){
                    m[secret[i]]++;
                }else
                    m.insert(pair<char,int>(secret[i],1));
            }
        }
        
        for(int i=0;i<g.length();i++){
            if(m.find(g[i])!=m.end()){
                cows++;
                m[g[i]]--;
                if(m[g[i]]==0)
                    m.erase(g[i]);
            }
        }
        
        string res = to_string(bulls) + "A" + to_string(cows) + "B";
        return res;
    }
};

//2.More compact comparison.
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        if(n==0)
            return "0A0B";
        
        int bulls = 0;
        int cows = 0;
        
        string g = "";
        unordered_map<char,int> m;
        for(int i=0; i<n; i++){
            if(secret[i]==guess[i]){
                bulls++;
            }else{
                g += guess[i];
                m[secret[i]]++;
            }
        }
        
        for(int i=0;i<g.length();i++){
            if(m.find(g[i])!=m.end()&&m[g[i]]!=0){
                cows++;
                m[g[i]]--;
            }
        }
        
        string res = to_string(bulls) + "A" + to_string(cows) + "B";
        return res;
    }
};

//3. Optimalized. But not understand.
class Solution {
public:
    string getHint(string secret, string guess) {
        int m[256] = {0}, a = 0, b = 0, i = 0;
        for (char s : secret) {
            char g = guess[i++];
            a += s == g;
            b += (m[s]++ < 0) + (m[g]-- > 0);
        }
        return to_string(a) + "A" + to_string(b - a) + "B";
    }
};