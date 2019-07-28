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
            result *= 10;
            result += x % 10;
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
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop; //只有确定不会超了才加上去变新的
        }
        return rev;
    }
};