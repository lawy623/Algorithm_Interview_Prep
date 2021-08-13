

class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        dfs(root);
        return root;
    }

    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->right);
        int tmp = root->val;
        root->val += sum;
        sum += tmp;
        dfs(root->left);
    }
};