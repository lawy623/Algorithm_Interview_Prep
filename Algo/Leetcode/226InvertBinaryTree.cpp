// recursive
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

// Use queue
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* t = q.front();
            swap(t->left, t->right);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
            q.pop();
        }
        return q;
    }
};