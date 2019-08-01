// 1, Use inorder search. All the visited nodes are larger than previous visited one.
class Checker {
public:
    bool checkBST(TreeNode* root) {
        if (!root)
            return false;
        stack<TreeNode*> s;
        int last = INT_MIN;
        while(!s.empty() || root) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                if (root->val <= last)
                    return false;
                last = root->val;
                s.pop();
                root = root->right;
            }
        }
        return true;
    }
};
