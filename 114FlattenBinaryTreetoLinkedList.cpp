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