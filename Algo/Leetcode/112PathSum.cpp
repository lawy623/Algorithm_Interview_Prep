// recursive
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right && root->val==targetSum) return true;
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};


// dfs
class Solution {
public:
    bool hasPath = false;
    void dfs(TreeNode* root, int target) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right && target == root->val) {
            hasPath = true;
        }
        dfs(root->left, target-root->val);
        dfs(root->right, target-root->val);
    }

   bool hasPathSum(TreeNode* root, int target) {
        dfs(root, target);
        return hasPath;
    }
};