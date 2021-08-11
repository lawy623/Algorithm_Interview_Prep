
class Solution {
public:
    vector<vector<int>> edges;
    vector<int> visit;
    bool valid = true;

    void dfs(int i){
        visit[i] = 1;
        for(auto e:edges[i]){
            if(visit[e]==0){
                dfs(e);
                if(!valid) return;
            } else if(visit[e]==1){
                valid=false;
                return;
            }
        }
        visit[i] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++){
            edges.push_back({});
            visit.push_back(0);
        }

        for(auto c:prerequisites) edges[c[1]].push_back(c[0]);

        for(int i=0; i<numCourses; i++){
            if(visit[i]==0) dfs(i);
            if(!valid) return false;
        }
        return true;
    }
};