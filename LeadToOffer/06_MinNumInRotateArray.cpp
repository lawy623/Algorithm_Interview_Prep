//1. binary search
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.size()==0)
            return 0;
        return minNum(rotateArray, 0, rotateArray.size()-1);
    }

    int minNum(vector<int> array, int start, int end) {
        if (start == end)
            return array[start];
        if (start == end-1 )
            return array[start] > array[end] ? array[end] : array[start];
        int mid = int( (start+end)/2 );
        if (array[mid]>array[end])
            return minNum(array, mid+1, end);
        else if (array[mid] == array[start] && array[mid] == array[end])
            return minNum(array, start+1, end-1);
        else
            return minNum(array, start, mid);
    }
};
