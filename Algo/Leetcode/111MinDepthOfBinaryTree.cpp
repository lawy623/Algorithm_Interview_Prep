// same as maxdepth. But if any of the children is 0, you can not use it, but use 1+l+r instead
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        return l&&r? 1+min(l,r) : 1+l+r;
    }
};