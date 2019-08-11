class Result {
public:
    vector<int> calcResult(string A, string guess) {
        map<int,bool> correct;
        int count1 = 0;
        int count2 = 0;
        for(int i=0; i<4; i++){
            if (A[i]==guess[i]){
                count1++;
                correct[i]=true;
            }
        }
        map<char,int> m;
        for(int i=0;i<4;i++){
            if (correct.find(i)==correct.end()){ // not the correct.
                if (m.find(A[i])!=m.end())
                    m[A[i]]++;
                else
                    m[A[i]]=1;
            }
        }
        for(int i=0; i<4; i++){
            if (correct.find(i)==correct.end()) {
                if (m.find(guess[i])!=m.end() && m[guess[i]]>0) {
                    count2++;
                    m[guess[i]]--;
                }
            }
        }
        vector<int> res;
        res.push_back(count1);
        res.push_back(count2);
        return res;
    }
};
