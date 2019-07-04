// method2. O(n^2) time. O(1) Space.
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.size()==0)
            return;
        for (int i=0; i<array.size()-1; i++){
            for (int j=0; j<array.size()-1; j++) {
                if (!(array[j]&1) && array[j+1]&1) {
                    swap(array[j], array[j+1]);
                }
            }
        }
        return;
    }
};
