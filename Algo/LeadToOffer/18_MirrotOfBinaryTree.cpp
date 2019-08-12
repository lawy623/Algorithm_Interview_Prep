// Recursively exchange left and right subtree of a non-leaf node.
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if (!pRoot)
            return;

        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return;
    }
};
