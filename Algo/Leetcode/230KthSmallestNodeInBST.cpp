// dfs
class Solution {
public:
    int res = 0;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }

    void dfs(TreeNode* root, int& count){
        if(!root || count < 0) return; // Do not need to go too deep

        dfs(root->left, count);
        count--;
        if(count == 0){
            res = root->val;
            return;
        }
        dfs(root->right, count);
    }
};