class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return root;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        root->left = mirrorTree(r);
        root->right = mirrorTree(l);
        return root;
    }
};