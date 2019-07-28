## Little bit hard. Consider all the conditions.
class Solution:
    def printMatrix(self, matrix):
        res = []
        if len(matrix)==0 or len(matrix[0])==0:
            return res
        start = 0
        row = len(matrix)
        col = len(matrix[0])
        while (2*start < row and 2*start <col):
            res.extend(self.printMatrixCycle(start, row, col, matrix))
            start += 1
        return res

    def printMatrixCycle(self, start, row, col, matrix):
        res = []
        end_col = col-start
        end_row = row-start

        for i in range(start, end_col):
            res.append(matrix[start][i])
        for i in range(start+1, end_row):
            res.append(matrix[i][end_col-1])
        if end_row-1 > start:
            for i in range(end_col-2, start-1, -1):
                res.append(matrix[end_row-1][i])
        if end_col-1 > start:
            for i in range(end_row-2, start, -1):  ## for range with neg stride, need to specify it.
                res.append(matrix[i][start])
        return res
