class Solution {
public:
    int findMin(vector<int>& numbers) {
        if(numbers.size() == 0)
            return 0;
        return minNum(numbers, 0, numbers.size()-1);
    }

    int minNum(vector<int> numbers, int start, int end) {
        if (start == end)
            return numbers[start];
        if (start == end-1 )
            return numbers[start] > numbers[end] ? numbers[end] : numbers[start];
        int mid = int( (start+end)/2 );
        if(numbers[mid] == numbers[start] && numbers[mid] == numbers[end])
            return minNum(numbers, start+1, end-1);
        else if(numbers[mid] > numbers[end])
            return minNum(numbers, mid+1, end);
        else
            return minNum(numbers, start, mid);
    }
};
