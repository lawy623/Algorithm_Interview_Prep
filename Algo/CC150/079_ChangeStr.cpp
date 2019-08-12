class Change {
public:
    int countDiff(string a, string b) {
        if (a.length()!=b.length())
            return -1;
        int n = a.length();
        int count = 0;
        for(int i=0;i<n;i++){
            if (a[i]!=b[i])
                count++;
        }
        return count;
    }
    int countChanges(vector<string> dic, int n, string s, string t) {
        if (!s.compare(t))
            return 0;
        vector<int> visit(n);
        map<string,int> m;
        for(int i=0;i<n;i++) {
            visit[i]=0;
            m[dic[i]]=i;
        }
        m[s]=-1;

        queue<string> q;
        q.push(s);
        while(!q.empty()){
            string tmp = q.front();
            if (tmp==t)
                return visit[m[t]];
            q.pop();
            for(int i=0; i<n; i++) {
                if (visit[i]==0 && countDiff(tmp, dic[i])==1) {
                    q.push(dic[i]);
                    if (m[tmp]==-1)
                        visit[i]=1;
                    else
                        visit[i]=visit[m[tmp]]+1;
                }
            }
        }
        return -1;
    }
};
