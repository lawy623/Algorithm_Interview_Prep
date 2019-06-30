//1.cpp version
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int n = array.size();
        if (array[0].size() == 0) {
            return false;
        }

        int row = 0;
        int col = n-1;
        while (row < n && col >= 0) {
            if (array[row][col] == target) {
                return true;
            } else if (array[row][col] < target) {
                row ++;
            } else {
                col --;
            }
        }
        return false;
    }
};
