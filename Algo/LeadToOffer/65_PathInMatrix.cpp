// 1. dfs
class Solution {
public:
    bool dfs(char *mat, int *&visit, int i, int j, int rows, int cols, char* str) {
        if (*str == '\0')
            return true;
        if (i<0 || i>=rows || j<0 || j>=cols)
            return false;
        if (mat[i*cols + j]==*str && visit[i*cols + j]==0) {
            visit[i*cols + j] = 1;
            char* str2 = str+1;
            bool found = dfs(mat, visit, i-1, j, rows, cols, str2) || dfs(mat, visit, i+1, j, rows, cols, str2)
                    || dfs(mat, visit, i, j-1, rows, cols, str2) || dfs(mat, visit, i, j+1, rows, cols, str2);
            if (found)
                return true;
            visit[i*cols + j] = 0;
        }
        return false;
    }
    bool hasPath(char *mat, int *&visit, int rows, int cols, char* str) {
        for (int i=0; i<cols; i++) {
            for (int j=0; j<cols; j++) {
                if (mat[i*cols + j] == *str) {
                    char* str2 = str; // in order not to overwrite the string
                    bool found = dfs(mat, visit, i, j, rows, cols, str2);
                    if (found)
                        return true;
                }
            }
        }
        return false;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        int* visit = new int[rows*cols];
        for (int i=0; i<rows*cols; i++)
            visit[i] = 0;
        return hasPath(matrix, visit, rows, cols, str);
    }
};
