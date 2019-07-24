// 1. Recursion and binary search. but too many stacks.
class Solution {
public:
    int getCount(TreeNode* pRoot) {
        if (!pRoot)
            return 0;
        return getCount(pRoot->left) + getCount(pRoot->right) + 1;
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (k<=0)
            return NULL;
        int leftCount = getCount(pRoot->left);
        if (leftCount==k-1)
            return pRoot;
        else if (leftCount>=k)
            return KthNode(pRoot->left, k);
        else
            return KthNode(pRoot->right, k-leftCount-1);
    }
};

// 2. recover the inorder result. Get the k-th value.
class Solution {
public:
    void InOrder(TreeNode* pRoot, vector<TreeNode*> &res) {
        if (!pRoot) return;

        if (pRoot->left) InOrder(pRoot->left, res);
        res.push_back(pRoot);
        if (pRoot->right) InOrder(pRoot->right, res);

        return;
    }
    vector<TreeNode*> InOrder(TreeNode* pRoot) {
        vector<TreeNode*> res;
        if (!pRoot)
            return res;
        InOrder(pRoot, res);
        return res;
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (k<=0)
            return NULL;
        vector<TreeNode*> inorder = InOrder(pRoot);
        if (k>inorder.size())
            return NULL;
        return inorder[k-1];
    }
};

// 3. Use stack for recursion. No saving all result.
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if (k<=0)
            return NULL;
        stack<TreeNode*> s;
        TreeNode* p = pRoot;
        int count = 0;
        while(!s.empty() || p) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                count ++;
                if (count==k)
                    return p;
                s.pop();
                p = p->right;
            }
        }
        return NULL;
    }
};
