// Little bit hard. Think about it.
class Solution {
public:

    bool SameSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot2)
            return true;
        if (!pRoot1)
            return false;

        if (pRoot1->val != pRoot2->val)
            return false;

        return SameSubtree(pRoot1->left, pRoot2->left) && SameSubtree(pRoot1->right, pRoot2->right);
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool result = false;

        if (pRoot1 && pRoot2) {
            if (pRoot1->val == pRoot2->val)
                result = SameSubtree(pRoot1, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->left, pRoot2);
            if (!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        }
        return result;
    }

};
