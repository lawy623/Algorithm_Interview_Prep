// First Sort. O(nlogn) time, O(n) space.
class Same {
public:
    bool checkSam(string stringA, string stringB) {
        int n1 = stringA.length();
        int n2 = stringB.length();
        if(n1!=n2)
            return false;
        sort(&stringA[0], &stringA[0]+n1);
        sort(&stringB[0], &stringB[0]+n2);
        if(stringA == stringB) return true;
        return false;
    }
};

// 2.Use space
class Same {
public:
    bool checkSam(string stringA, string stringB) {
        int n1 = stringA.length();
        int n2 = stringB.length();
        if (n1!=n2)
            return false;
        int times[256];
        for(int i=0;i<256;i++)
            times[i]=0;
        for(int i=0;i<n1;i++)
            times[(int)stringA[i]]++;
        for(int i=0;i<n2;i++){
            int pos = (int)stringB[i];
            if (times[pos]==0)
                return false;
            times[pos]--;
        }
        return true;
    }
};
