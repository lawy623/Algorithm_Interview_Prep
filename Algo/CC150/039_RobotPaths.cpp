// 1. recursion
class Robot {
public:
    int countWays(int x, int y) {
        if (x==1 || y==1)
            return 1;
        return countWays(x-1, y) + countWays(x, y-1);
    }
};

// 2. By combination
class Robot {
public:
    int fac(int x){
        if (x==1)
            return x;
        return x*fac(x-1);
    }
    int countWays(int x, int y) {
        if (x==1 || y==1)
            return 1;
        return fac(x+y-2) / fac(x-1) / fac(y-1);
    }
};
