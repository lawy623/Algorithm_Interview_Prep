// 1.Use a 256 bool array for each array.
class Different {
public:
    bool checkDifferent(string iniString) {
        bool appear[256];
        for (int i=0; i<256; i++){
            appear[i]=false;
        }
        int n = iniString.length();
        if (n==0)
            return true;
        for(int i=0; i<n; i++) {
            int pos = (int)iniString[i];
            if (appear[pos])
                return false;
            appear[pos]=true;
        }
        return true;
    }
};

//2. Use a bit map with int[8] to store 256 positions.
class Different {
public:
    bool checkDifferent(string iniString) {
        int appear[8];
        for (int i=0; i<8; i++){
            appear[i]=0;
        }
        int n = iniString.length();
        if (n==0)
            return true;
        for(int i=0; i<n; i++) {
            int pos = (int)iniString[i];
            if(appear[pos/32] & (1 <<pos%32))
                return false;
            appear[pos/32] |= 1 << (pos%32);
        }
        return true;
    }
};
