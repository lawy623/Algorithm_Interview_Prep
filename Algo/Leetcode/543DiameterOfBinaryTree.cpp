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
