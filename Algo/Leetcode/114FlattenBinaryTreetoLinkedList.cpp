//1. Flatten both left and right. Move left to the right.
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        
        flatten(root->left);
        flatten(root->right);
        
        if(!root->left) return;
        
        TreeNode* Lend = root->left;
        while(Lend->right){
            Lend = Lend->right;
        }
        Lend -> right = root->right;
        root -> right = root ->left;
        root ->left = nullptr;
    }
};

// same dfs
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        dfs(root);
    }

    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        if(root->left){
            TreeNode* tmp = root->left;
            while(tmp->right)
                tmp = tmp->right;
            tmp->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};