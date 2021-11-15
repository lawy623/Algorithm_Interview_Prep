//主要考查的是bit溢出问题
//1.定义好比int更长的long long
class Solution {
public:
    int reverse(int x) {
        
        long long result=0;
        long long max = ((long long)1<<31)-1;  //2^31 - 1
        long long min = 0 - (1 << 31);         //-2^31
        while(x)
        {
            result = result * 10 + x % 10;
            x = x /10;
        }
        return result>max || result < min?0:result;
    }
};

//2. 16ms
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x) {
            auto prev = result;
            result = result * 10 + x % 10;  //  but it will get wrong in some case that overflow already
            if (result / 10 != prev) {  //已经溢出，才会导致此处不等
                result = 0;
                break;
            }
            x /= 10;
        }
        return result;
    }
};


//3. 16ms 
class Solution {
public:
    int reverse(int x){
        int res = 0;

        while(x!=0){
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && x % 10 > 7)) return 0;  // last digit of INT_MAX is 7
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && x % 10 < -8)) return 0; // last digit of INT_MIN is 8
            res = res * 10 + x % 10;   // we should ensure this will not overflow
            x = x / 10;
        }
        return res;
    }
};