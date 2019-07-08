// Recursively exchange left and right subtree of a non-leaf node.
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (!pRoot)
            return;

        TreeNode* temp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = temp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return;
    }
};
