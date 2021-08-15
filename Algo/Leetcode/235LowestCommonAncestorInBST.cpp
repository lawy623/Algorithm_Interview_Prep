class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* move = root;
        while(move){
            if(move->val > p->val && move->val > q->val)
                move = move->left;
            else if (move->val < p->val && move->val < q->val)
                move = move->right;
            else
                return move;
        }
        return NULL;
    }
};