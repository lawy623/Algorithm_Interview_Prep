class Solution {
public:
    int res = -1;
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return -1;
        if(!root->left || !root->right) return -1;
        dfs(root, root->val);
        return res;
    }

    void dfs(TreeNode* root, int m){
        if(!root) return;
        if(root->val > m && (root->val < res || res == -1))
            res = root->val;
        dfs(root->left, m);
        dfs(root->right, m);
    }
};