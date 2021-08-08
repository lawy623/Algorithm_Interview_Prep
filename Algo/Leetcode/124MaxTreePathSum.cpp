// recursive
class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        maxSum(root);
        return res;
    }

    int maxSum(TreeNode* root){
        if(!root) return 0;

        int l = max(maxSum(root->left), 0);  // only significant node is fine.
        int r = max(maxSum(root->right), 0);

        int max_sum = l + r + root->val;
        res = max(max_sum, res);

        return root->val + max(l, r);  // You can not select both l and r for this node
    }
};