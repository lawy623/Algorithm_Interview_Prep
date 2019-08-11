// 1. BFS. Use the map as count. And push a single pos into the queue.
class Flood {
public:
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    int floodFill(vector<vector<int> > map, int n, int m) {
        for(int i=0; i<n; i++) {
            for (int j=0; j<m; j++)
                if (map[i][j]==1) map[i][j] = -1;
        }
        queue<int> q;
        q.push(0);
        map[0][0]=1;
        int pos=0, x=0, y=0, next_x=0, next_y=0;
        while(!q.empty()) {
            pos = q.front();
            q.pop();
            x = pos / m;
            y = pos % m;
            if (x==n-1 && y==m-1)
                return map[x][y]-1;
            for(int i=0; i<4; i++) {
                next_x = x+dir[i][0];
                next_y = y+dir[i][1];
                if (next_x>=0&&next_x<=n-1&&next_y>=0&&next_y<=m-1&&map[next_x][next_y]==0) {
                    q.push(next_x*m+next_y);
                    map[next_x][next_y]=map[x][y]+1;
                }
            }
        }
        return -1;
    }
};
