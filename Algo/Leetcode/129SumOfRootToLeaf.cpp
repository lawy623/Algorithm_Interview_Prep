class Solution {
public:

    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        int sum = dfs(root, 0);
        return sum;
    }

    int dfs(TreeNode* root, int sum){
        if(!root) return 0;

        sum = sum * 10 + root->val;
        if(!root->left && !root->right)
            return sum;

        return dfs(root->left, sum) + dfs(root->right, sum);
    }
};