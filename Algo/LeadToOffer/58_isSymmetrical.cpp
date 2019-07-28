// 1. Mirror the tree and check whether two trees are the same. But repeative visit and need more space.
class Solution {
public:
    TreeNode* mirror(TreeNode* pRoot) {
        if (!pRoot)
            return NULL;
        TreeNode* root = new TreeNode(pRoot->val);
        root->left = mirror(pRoot->right);
        root->right = mirror(pRoot->left);
        return root;
    }
    bool isSameTree(TreeNode* p1, TreeNode* p2) {
        if (!p1 && !p2)
            return true;
        if (!p1 || !p2)
            return false;
        if (p1->val != p2->val)
            return false;
        return isSameTree(p1->left, p2->left) && isSameTree(p1->right, p2->right);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (!pRoot)
            return true;
        if (!pRoot->left && !pRoot->right)
            return true;
        if (!pRoot->left || !pRoot->right)
            return false;
        TreeNode* pRoot_mirror = mirror(pRoot);
        return isSameTree(pRoot, pRoot_mirror);
    }
};

// 2. Recursive check whether two trees are symmetrical.
class Solution {
public:
    bool isSym(TreeNode* p1, TreeNode* p2) {
        if (!p1 && !p2)
            return true;
        if (!p1 || !p2)
            return false;
        if (p1->val != p2->val)
            return false;
        return isSym(p1->left, p2->right) && isSym(p1->right, p2->left);
    }
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (!pRoot)
            return true;
        return isSym(pRoot->left, pRoot->right);
    }
};
