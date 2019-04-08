//1. Recursion. O(N)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetric(root->left,root->right);
    }
    
    bool isSymmetric(TreeNode* p,TreeNode* q) {
        if(!p && q || p && !q) return false;
        if(!p && !q) return true;
        if(p && q) return (p->val==q->val) && isSymmetric(p->left,q->right) && isSymmetric(q->left,p->right);
    }
};

//2. Iteration. O(n)
class Solution{
public:
    bool isSymmetric(TreeNode *root) {
        if(!root) return true;
        stack<TreeNode*> s;
        s.push(root->left);
        s.push(root->right);
        while(!s.empty()) {
            TreeNode *p = s.top(); s.pop();
            TreeNode *q = s.top(); s.pop();
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            s.push(p->left);
            s.push(q->right);
            s.push(p->right);
            s.push(q->left);
        }
        return true;
    }
};