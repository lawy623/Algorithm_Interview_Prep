class Frequency {
public:
    int getFrequency(vector<string> article, int n, string word) {
        map<string, int> hashtable;
        for (int i = 0; i < n; i++) {
            hashtable[article[i]]++;
        }

        return hashtable[word];
    }
};
