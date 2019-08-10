// For each new line, check whether the new assignment is valid or invalid compared to past assignments.
class Queens {
public:
    int rows[15];
    void search(int row, int n, int &count) {
        if (row==n){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            rows[row] = i;
            int valid = 1;
            for(int j=0; j<row; j++){
                if (rows[j]==rows[row]||row-j==rows[row]-rows[j]||row-j==rows[j]-rows[row]){
                    valid=0;
                    break;
                }
            }
            if (valid)
                search(row+1, n, count);
        }
    }
    int nQueens(int n) {
        int count = 0;
        search(0, n, count);
        return count;
    }
};
