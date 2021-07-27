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

// 2. dfs
class Solution {
public:
    int max_depth = 0;
    int maxDepth(TreeNode* root) {
        int dep = 0;
        dfs(root, dep);
        return max_depth;
    }

    void dfs(TreeNode* root, int& dep){
        if(!root) return;
        dep++;
        if(dep > max_depth) max_depth = dep;
        dfs(root->left, dep);
        dfs(root->right, dep);
        dep--;
    }
};