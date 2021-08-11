// dfs on graph. Find whether there is cycle
class Solution {
public:
    vector<vector<int>> edges;
    vector<int> visit;
    vector<int> res;
    bool valid = true;

    void dfs(int i){
        visit[i] = 1;
        for(auto e:edges[i]){
            if(visit[e]==0){
                dfs(e);
                if(!valid) return;
            } else if (visit[e]==1){  // revisit during dfs, it becomes invalid cycle
                valid=false;
                return;
            }
        }
        visit[i] = 2;
        res.push_back(i);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++){
            visit.push_back(0);
            edges.push_back({});
        }

        for(auto c: prerequisites)
            edges[c[1]].push_back(c[0]);

        for(int i=0; i<numCourses && valid; i++){
            if(visit[i]==0) dfs(i);

            if(!valid) return {};
        }

        reverse(res.begin(), res.end());
        return res;

    }
};