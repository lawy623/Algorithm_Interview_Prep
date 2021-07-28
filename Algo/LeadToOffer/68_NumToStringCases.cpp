//recursive
class Solution {
public:
    int translateNum(int num) {
        if(num < 10)
            return 1;
        if(num < 26)
            return 2;
        if(num < 100)
            return 1;

        return translateNum(num / 10) + translateNum(num / 100) * (translateNum(num % 100) - 1);
    }
};

// dp
class Solution {
public:
    int translateNum(int num) {
        if(num < 10)
            return 1;
        if(num < 26)
            return 2;
        if(num < 100)
            return 1;

        int f1 = 1; int f2 = 1; int f;
        string v = to_string(num);
        int digit = v.length();
        for(int i = 2; i <= digit; i++){
            int k = stoi(v.substr(i-2, 2));
            f = f1 + f2 * (k >= 10 && k <= 25);

            f2 = f1;
            f1 = f;
        }
        return f;
    }
};