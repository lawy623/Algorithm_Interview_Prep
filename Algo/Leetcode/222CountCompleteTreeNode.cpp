// early stop
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};


// early stop
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        int l_d = 0; int r_d = 0;
        while(l){
            l = l->left;
            l_d++;
        }
        while(r){
            r = r->right;
            r_d++;
        }
        if(l_d == r_d) return (1<<l_d+1) - 1;   //fully complete tree

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};