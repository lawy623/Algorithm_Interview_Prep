class FindPair {
public:
    int countPairs(vector<int> A, int n, int sum) {
        map<int, int> occur;
        int count = 0;
        for(int i=0; i<n; i++) {
            int diff = sum-A[i];
            if (occur.find(diff)!=occur.end())
                count += occur[diff];
            if (occur.find(A[i])==occur.end())
                occur[A[i]]=1;
            else
                occur[A[i]]++;
        }
        return count;
    }
};
