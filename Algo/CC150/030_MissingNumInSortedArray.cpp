// The last bit is always 0/1 switching in sorted array. Take care about the last.
class Finder {
public:
    int findMissing(vector<vector<int> > numbers, int n) {
        for(int i=0; i<n; i++){
            int query = numbers[i][0];
            if (query != i%2)
                return i;
        }
        return n;
    }
};
