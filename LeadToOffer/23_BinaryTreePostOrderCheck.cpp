// Key point is the last val is root. And the former should be seperated by root in order.
class Solution {
public:
    int findFirstLarger(vector<int> seq, int start, int end, int val) {
        for (int i = start; i <= end; i++) {
            if (seq[i]>val)
                return i;
        }
        return end+1;
    }

    bool verify(vector<int> seq, int start, int end) {
        if (start == end || start == end-1)
            return true;

        int root = seq[end];
        int idx = findFirstLarger(seq, start, end-1, root);
        for(int i=start; i<idx; i++) {
            if (seq[i]>root)
                return false;
        }
        for (int i=idx; i<end; i++) {
            if (seq[i]<root)
                return false;
        }

        bool res = true;
        if (idx-1 > start)
            res = res && verify(seq, start, idx-1);
        if (idx < end-1)
            res = res && verify(seq, idx, end-1);
        return res;
    }


    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size()==0)
            return false;

        return verify(sequence, 0, sequence.size()-1);
    }
};
