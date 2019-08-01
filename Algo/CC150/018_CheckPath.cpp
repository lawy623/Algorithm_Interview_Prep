// DFS
class Path {
public:
    bool isPath(UndirectedGraphNode* a, UndirectedGraphNode* b, map<UndirectedGraphNode*, bool> &visit){
        if (!a || !b)
            return false;
        if (a==b)
            return true;
        visit[a] = true;
        for(int i=0; i<a->neighbors.size(); i++) {
            if (a->neighbors[i]==b || (visit.find(a->neighbors[i])==visit.end() && isPath(a->neighbors[i], b, visit)))
                return true;
        }
        //visit.erase(a);
        // *** You don't need to reset it since if you can not go from a, you do not need to check it next time.
        return false;
    }
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        if (!a || !b)
            return false;
        map<UndirectedGraphNode*, bool> visit;
        return isPath(a,b, visit) || isPath(b,a, visit);
    }
};


// BSF
class Path {
public:
    bool isPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        if (!a || !b)
            return false;
        if (a==b)
            return true;
        queue<UndirectedGraphNode*> q;
        map<UndirectedGraphNode*, bool> visit;
        q.push(a);
        visit[a] = true;
        while(!q.empty()) {
            UndirectedGraphNode* head = q.front();
            q.pop();
            for(int i=0; i<head->neighbors.size(); i++) {
                if (head->neighbors[i]==b)
                    return true;
                if (visit.find(head->neighbors[i])==visit.end()) {
                    q.push(head->neighbors[i]);
                    visit[head->neighbors[i]] = true;
                }
            }
        }
        return false;
    }
    bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b) {
        return isPath(a,b) || isPath(b,a);
    }
};
