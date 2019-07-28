#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

int get_sum(int i, int j) {
    int sum = 0;
    if (i<0 || j<0)
        return 0;
    while(i!=0) {
        sum += i%10;
        i /= 10;
    }
    while(j!=0) {
        sum += j%10;
        j /= 10;
    }
    return sum;
}
void dfs(vector<vector<int> > &visit, int k, int i, int j, int rows, int cols, int &count) {
    if (i<0 || i>=rows || j<0 || j>=cols || visit[i][j]==1 || get_sum(i,j)>k)
        return;
    count++;
    visit[i][j]=1;
    dfs(visit, k, i-1, j, rows, cols, count);
    dfs(visit, k, i+1, j, rows, cols, count);
    dfs(visit, k, i, j-1, rows, cols, count);
    dfs(visit, k, i, j+1, rows, cols, count);
    return;
}
int movingCount(int threshold, int rows, int cols)
{
    if (rows<=0 || cols<=0)
        return 0;
    vector<vector<int> > visit;
    for(int i=0; i<rows; i++) {
        vector<int> row_num;
        for(int j=0; j<cols; j++) {
            row_num.push_back(0);
        }
        visit.push_back(row_num);
    }
    int count = 0;
    dfs(visit, threshold, 0, 0, rows, cols, count);
    return count;
}


int main()
{
    int arr [] = {1,2,2,3,0,1};
    vector<int> vec (arr, arr+(sizeof(arr)/sizeof(arr[0])) );
    int count = movingCount(10, 100, 100);

    return 0;
}
