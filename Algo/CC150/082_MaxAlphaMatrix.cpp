class AlphaMatrix {
public:
    int findAlphaMatrix(vector<string> dic, int n) {
        map<string,int> mapp;
        int res=0;
        int maxv=0;
        for(int i=0;i<n;i++){
            mapp[dic[i]]++;
            res = res>dic[i].length()*mapp[dic[i]]? res : dic[i].length()*mapp[dic[i]];
        }
        return res;
    }
};
