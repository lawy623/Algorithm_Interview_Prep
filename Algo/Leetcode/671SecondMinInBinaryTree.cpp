class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        if(!root->left || !root->right) return -1;

        int res = -1;
        dfs(root, res, root->val);
        return res;
    }

    void dfs(TreeNode* root, int& res, int m){
        if(!root) return;
        if(root->val > m && (root->val < res || res == -1))
            res = root->val;
        if(root->left){
            dfs(root->left, res, m);
            dfs(root->right, res, m);
        }
    }
};