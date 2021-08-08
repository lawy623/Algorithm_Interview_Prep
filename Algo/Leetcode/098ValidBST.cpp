// use a pointer
class Solution {
public:
    bool isBST = true;
    TreeNode* pre = NULL;
    bool isValidBST(TreeNode* root) {
        if(!root) return isBST;
        dfs(root);
        return isBST;
    }

    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->left);
        if(!pre) pre = root;
        else {
            if(pre->val >= root->val)
                isBST = false;
        }
        pre = root;
        dfs(root->right);
    }
};

// use a single value. But this is not correct if some value is INT_MIN in the tree.
class Solution {
public:
    bool isBST = true;
    int last_val = INT_MIN;
    bool isValidBST(TreeNode* root) {
        if(!root) return isBST;
        dfs(root);
        return isBST;
    }

    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->left);
        if(last_val >= root->val) isBST = false;
        last_val = root->val;
        dfs(root->right);
    }
};