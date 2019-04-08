//1. Use inorder sort for binary search tree. Change the wrong pointers.
class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode *> res = inorderTraversal(root);
        
        TreeNode * l = nullptr;
        TreeNode * r = nullptr;
        for(int i=0;i<res.size()-1;i++){
            if(res[i]->val > res[i+1]->val) {l = res[i];break;}
        }
        for(int i=res.size()-1;i>0;i--){
            if(res[i]->val < res[i-1]->val) {r = res[i];break;}
        }
        int temp = r->val;
        r->val = l->val;
        l->val = temp;
    }
    
    vector<TreeNode *> inorderTraversal(TreeNode* root) {
        vector<TreeNode *> res;
        if(!root) return res;
        
        inorderTraversal(root,res);
        return res;
    }
    
    void inorderTraversal(TreeNode* root, vector<TreeNode *>& res) {
        if(!root) return;
        
        if(root->left) inorderTraversal(root->left,res);
        res.push_back(root);
        if(root->right) inorderTraversal(root->right,res);    
    }
};