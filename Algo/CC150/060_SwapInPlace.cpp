// 1. Minus
class Exchange {
public:
    vector<int> exchangeAB(vector<int> AB) {
        AB[1] = AB[0] - AB[1];
        AB[0] = AB[0] - AB[1];
        AB[1] = AB[1] + AB[0];
        return AB;
    }
};

// 2. XOR
class Exchange {
public:
    vector<int> exchangeAB(vector<int> AB) {
        AB[1] = AB[0] ^ AB[1];
        AB[0] = AB[0] ^ AB[1];
        AB[1] = AB[0] ^ AB[1];
        return AB;
    }
};
