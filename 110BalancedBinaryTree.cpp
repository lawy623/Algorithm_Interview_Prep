class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return diffHeigh(root)>=0; 
    }
    
    int diffHeigh(TreeNode* root){
        if(!root) return 0;
        
        int left = diffHeigh(root->left);
        int right = diffHeigh(root->right);
        
        if(left<0 || right<0 || abs(left-right)>1) return -1;  //If left or right has unbalanced component, return -1 anyway.
        
        return max(left,right)+1;
    }
};