// reverse inorder
class Solution {
public:
    int val = 0;
    int kthLargest(TreeNode* root, int k) {
        dfs(root, k);
        return val;
    }

    void dfs(TreeNode* root, int& k){
        if(!root) {k--; return;}

        dfs(root->right, k);
        if(k==0) val = root->val;
        dfs(root->left, k);
    }
};