// 1. d(p) = max(max(d(p->left), d(p->right)), depth_left+depth_right)
class Solution {
public:
    int diameter(TreeNode* root, int &depth) {
        if (!root)
            return 0;
        int depth_left = 0;
        int depth_right = 0;
        int dm_left = diameter(root->left, depth_left);
        int dm_right = diameter(root->right, depth_right);
        depth = max(depth_left, depth_right) + 1;
        return max(max(dm_left, dm_right), depth_left+depth_right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        int depth = 0;
        return diameter(root, depth);
    }
};


//
class Solution {
public:
    int max_d = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        dfs(root);
        return max_d-1;
    }

    int dfs(TreeNode* root){ // max sum of depth pass root
        if(!root) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        max_d = max(max_d, L+R+1); // key record of every max path
        return max(L, R) + 1;
    }
};