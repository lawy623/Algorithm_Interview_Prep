//1. Recursion
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if (!pRoot)
            return 0;
        if (!pRoot->left && !pRoot->right)
            return 1;
        return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
    }
};
