// 1. Use vector. Keep it sorted like insertion sort. O(n) time for insertion, O(1) for getMedian.
class Solution {
public:
    void Insert(int num)
    {
        nums.push_back(num);
        for(int i=count-1; i>=0; i--) {
            if (nums[i]>nums[i+1])
                swap(nums[i], nums[i+1]);
        }
        count ++;
    }

    double GetMedian()
    {
        return (nums[(count-1)>>1] + nums[count>>1]) / 2.0;
    }
private:
    int count = 0;
    vector<int> nums;

};


// 2. Use max heap and min heap. O(logn) time for insertion, O(1) for getMedian.
class Solution {
public:
    void Insert(int num)
    {
        if (count&1) { // to min heap. First go max and get the max
            max_q.push(num);
            min_q.push(max_q.top());
            max_q.pop();
        } else { // To max heap. First go min heap and get the min
            min_q.push(num);
            max_q.push(min_q.top());
            min_q.pop();
        }
        count ++;
    }

    double GetMedian()
    {
        if (count&1)
            return max_q.top();
        else
            return (max_q.top() + min_q.top()) / 2.0;
    }
private:
    int count = 0;
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int> > min_q;

};
