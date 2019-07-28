// 1. same as q22. But need to keep each level's size, and push to the result.
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int> > res;
            if (!pRoot)
                return res;

            queue<TreeNode*> vals;
            vals.push(pRoot);
            TreeNode* temp;
            while(!vals.empty()) {
                int n = vals.size();
                vector<int> level;
                for (int i=0; i<n; i++) {
                    temp = vals.front();
                    level.push_back(temp->val);
                    vals.pop();
                    if (temp->left)
                        vals.push(temp->left);
                    if (temp->right)
                        vals.push(temp->right);
                }
                res.push_back(level);
            }
            return res;
        }
};
