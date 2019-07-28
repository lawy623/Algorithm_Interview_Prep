//1. Use hash table. O(n) time, O(n) space.
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length==0 || numbers==NULL)
            return false;
        for (int i=0; i<length; i++) {
            if (numbers[i]>length-1 || numbers[i]<0)
                return false;
        }

        unordered_map<int,int> count;
        for (int i=0; i<length; i++) {
            if (count.find(numbers[i])!=count.end()) {
                *duplication = numbers[i];
                return true;
            }
            count[numbers[i]] = 1;
        }
        return false;
    }
};

//2. Move each number to its index position. O(1) space, O(n) time.
class Solution {
public:
    bool duplicate(int numbers[], int length, int* duplication) {
        if (length==0 || numbers==NULL)
            return false;
        for (int i=0; i<length; i++) {
            if (numbers[i]>length-1 || numbers[i]<0)
                return false;
        }
        for (int i=0; i<length; i++) {
            while(i!=numbers[i]) {
                if ( numbers[i] == numbers[numbers[i]] ) {
                    *duplication = numbers[i];
                    return true;
                }
                int temp = numbers[numbers[i]];
                numbers[numbers[i]] = numbers[i];
                numbers[i] = temp;
            }
        }
        return false;
    }
};
