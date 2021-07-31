class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* move = root;
        while(move){
            if(move->val > p->val && move->val > q->val)
                move = move->left;
            else if (move->val < p->val && move->val < q->val)
                move = move->right;
//            else if(move->val == p->val)
//                return p;
//            else if(move->val == q->val)
//                return q;
            else
                return move;
        }
        return NULL;
    }
};