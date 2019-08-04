// Float/double in demciaml place is 1/2^i
class BinDecimal {
public:
    string printBin(double num) {
        if(num>1 || num<0)
            return "";
        string res="0.";
        double base = 0.5;
        int count=0;
        while(num>0) {
            if (count==32)
                return "Error";
            if (num>=base){
                res += '1';
                num -= base;
            } else{
                res += '0';
            }
            base /= 2;
            count ++;
        }
        return res;
    }
};
