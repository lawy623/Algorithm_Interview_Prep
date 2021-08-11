// brute force recursive
class Solution {
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        int m = root->val;
        if(root->left)
            m += rob(root->left->left) + rob(root->left->right);

        if(root->right)
            m += rob(root->right->left) + rob(root->right->right);

        return max(m, rob(root->left) + rob(root->right));
    }
};

// use vector<int> to include the case of self-selected and not-selected
class Solution {
public:
    int rob(TreeNode* root) {
        if(!root) return 0;
        vector<int> res = dfs(root);
        return max(res[0], res[1]);
    }

    vector<int> dfs(TreeNode* root){
        vector<int> res{0,0};
        if(!root) return res;
        vector<int> l = dfs(root->left);
        vector<int> r = dfs(root->right);
        res[0] = max(l[0], l[1]) + max(r[0], r[1]);
        res[1] = root->val + l[0] + r[0];
        return res;
    }
};