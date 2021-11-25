// O(1) time and space
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest){
        int numTest = minutesToTest / minutesToDie + 1;
        int numPigs = (int) ceil( (float) log(buckets) / (float) log(numTest));
        return numPigs;
    }
};

// 对于 minutesToDie， minutesToTest 来说， 最多一只猪可以测试 Test/Die + 1轮。 在某个区间内死亡或者最后未死亡又能找到最后的结果
// 对于 两只猪而言， 最多可以测试 (test/Die + 1)^ 2个。 将所有的buckets想象成正方形二维数组， 两只猪分别在时间区间内喝行、列的混合用水 ，可以定位到有毒的水
// 因此， 最少的猪的数量要满足 (test/Die + 1)^n >= buckets, 因此 n >= log(buckets) / log(test/die+1), 取值即为 ceil(log(buckets) / log(test/die+1))