// Use Queue for level print
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;

        queue<TreeNode*> vals;
        vals.push(root);
        TreeNode* temp;
        while(!vals.empty()) {
            temp = vals.front();
            vals.pop();
            res.push_back(temp->val);
            if (temp->left)
                vals.push(temp->left);
            if (temp->right)
                vals.push(temp->right);
        }

        return res;
    }
};
