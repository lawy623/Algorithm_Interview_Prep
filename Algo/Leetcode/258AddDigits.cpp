// 能被9除，则为9. 否则余数就是最后的结果
class Solution {
public:
    int addDigits(int num) {
        if(num<10) return num;
        return num%9 == 0?9:num%9;
    }
};

// 更加简化
class Solution {
public:
    int addDigits(int num) {
        return (num-1)%9+1;
    }
};