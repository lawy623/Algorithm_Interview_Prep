//simple BFS.
class Solution {
public:
    void bfs(vector<vector<char>> &grid, int i, int j){
        grid[i][j] = '0';
        if(i>0 && grid[i-1][j]=='1'){
            bfs(grid, i-1, j);
        }
        if(i<grid.size()-1 && grid[i+1][j]=='1'){
            bfs(grid, i+1, j);
        }
        if(j>0 && grid[i][j-1]=='1'){
            bfs(grid, i, j-1);
        }
        if(j<grid[0].size()-1 && grid[i][j+1]=='1'){
            bfs(grid, i, j+1);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        if(grid[0].size()==0) return 0;
        
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    bfs(grid, i, j);
                    count ++;
                }
            }
        }
        return count;
    }  
};