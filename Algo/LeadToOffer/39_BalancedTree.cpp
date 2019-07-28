//1. Use depth and recursion. But repeat computation.
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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot)
            return true;
        if (abs(TreeDepth(pRoot->left)-TreeDepth(pRoot->right))>1)
            return false;
        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};


//2. Recursion but keep track of the depth bottom up. Reduce repeat access.
class Solution {
public:
    bool IsBalanced(TreeNode* pRoot, int* depth){
        if (!pRoot) {
            *depth = 0;
            return true;
        }
        int left = 0, right = 0;
        if (IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)) {
            if (abs(left-right)<=1) {
                *depth = max(left, right) + 1;
                return true;
            }
        }
        return false;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if (!pRoot)
            return true;
        int depth = 0;
        return IsBalanced(pRoot, &depth);
    }
};
