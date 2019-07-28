// 1. Use two stacks. O(n) time. O(n) space.
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > res;
        if (!pRoot)
            return res;
        bool left_to_right = false;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(pRoot);
        while (!s1.empty() || !s2.empty()) {
            left_to_right = !left_to_right;
            vector<int> level;
            if (left_to_right) {
                while(!s1.empty()) {
                    if(s1.top()->left)
                        s2.push(s1.top()->left);
                    if(s1.top()->right)
                        s2.push(s1.top()->right);
                    level.push_back(s1.top()->val);
                    s1.pop();
                }
            } else {
                while(!s2.empty()) {
                    if(s2.top()->right)
                        s1.push(s2.top()->right);
                    if(s2.top()->left)
                        s1.push(s2.top()->left);
                    level.push_back(s2.top()->val);
                    s2.pop();
                }
            }
            res.push_back(level);
        }
        return res;
    }
};
