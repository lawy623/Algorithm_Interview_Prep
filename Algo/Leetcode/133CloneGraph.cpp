/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> visit;
    Node* dfs(Node* node) {
        if (!node)
            return NULL;

        if (visit.find(node) != visit.end())
            return visit[node];

        Node* clone_node = new Node(node->val);
        visit[node] = clone_node;

        for (auto p: node->neighbors) {
            clone_node->neighbors.push_back(dfs(p));
        }

        return clone_node;
    }
    Node* cloneGraph(Node* node) {
        return dfs(node);

    }
};