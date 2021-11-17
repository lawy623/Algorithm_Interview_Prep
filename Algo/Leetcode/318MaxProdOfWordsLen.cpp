// use bits to represent words(char dict).
// O(n^2+L) time, O(n) space
class Solution {
public:
    int strToBit(string& a){
        int b = 0;
        for(char c:a)
            b |= (1 << (int)(c-'a'));
        return b;
    }

    int maxProduct(vector<string>& words){
        int n = words.size();
        int res = 0;
        vector<int> bitMap;
        vector<int> wordLen;
        for(string w:words){
            bitMap.push_back(strToBit(w));
            wordLen.push_back(int(w.length()));
        }
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                if((bitMap[i]&bitMap[j])==0)
                    res = max(res, wordLen[i]*wordLen[j]);
            }
        }
        return res;
    }
};


// 用dict保存相同bitmap下的最大长度， 最后遍历， 会稍微优化一点
class Solution {
public:
    int strToBit(string& a){
        int b = 0;
        for(char c:a)
            b |= (1 << (int)(c-'a'));
        return b;
    }

    int maxProduct(vector<string>& words){
        int n = words.size();
        int res = 0;

        map<int, int> wordLen;
        for(string w:words){
            int b = strToBit(w);
            if(wordLen.find(b) != wordLen.end())
                wordLen[b] = max(wordLen[b], int(w.length()));
            else
                wordLen[b] = int(w.length());
        }
        for(auto it1=wordLen.begin(); it1!=wordLen.end(); it1++){
            for(auto it2=wordLen.begin(); it2!=wordLen.end(); it2++){
                if((it1->first & it2->first)==0)
                    res = max(res, it1->second * it2->second);
            }
        }
        return res;
    }
};