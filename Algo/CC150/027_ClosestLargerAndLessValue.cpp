class CloseNumber {
public:
    vector<int> getCloseNumber(int x) {
        // write code here
        vector <int> result;
        if (x == 0 || x == INT_MAX)
            return result; //00..00, and 0111...1 will not have exact num of 1's
        int c_0 = 0; // last zeros
        int c_01 = 0; // last zeros left ones till zero
        int c_1 = 0; // last ones
        int c_10 = 0; // last ones left zeros till 1

        int c = x;
        int d = x;
        while( ((c&1)==0) && (c!=0) ){ //10011100 : c_0 = 2
            c_0++;
            c>>=1;
        }
        while( (c&1)==1 ){ //10011100 : c_01 = 3
            c_01++;
            c>>=1;
        }
        while( (d&1)==1 ){ // 10011100: c_1 = 0
            c_1++;
            d>>=1;
        }
        while ( ((d&1)==0) && (d!=0) ){  // 10011100: c_10 = 2
            c_10++;
            d>>=1;
        }
        int min = (x - (1<<c_1) - (1<<(c_10-1)) + 1);
        int max = (x + (1<<c_0) + (1<<(c_01-1)) -1);
        result.push_back(min);
        result.push_back(max);
        return result;
    }
};

// For 10011100, next max is 10100011, next min is 10011010
// next max: let the first zeor after 1..10..0 to be 1, setting all the afterwards to 0, and make last to be 1 with exactly amount
// next min: left the first one after 0..01..1 to be 0, setting all the afterwards to 1, and make the last to be 0 with exactly amount.
// For 10011100:
// max : 10011100(x)->10100000(x+1<<c_0, where c_0=2)->10100011(x+1<<c_0+1<<(c_01-1)-1,where c_01=3, make 2 more 1s at last, so 1<<(c_01-1)-1 is 11)
// min : 10011100(x)->10011011(x-(1<<c_1 -1)-1 = x-1<<c_1), where c_1=0)->10011010(x-1<<c_1-1<<(c_10-1+1),where c_10=2)
// or say for 110011, find min: first remove 11 and -1 more, 11=1<<c_1-1, in all becomes x-1<<c_1
// then make 101111->101110, that is remove the c_10-1 1's, by - 1<<(c_10-1) + 1
