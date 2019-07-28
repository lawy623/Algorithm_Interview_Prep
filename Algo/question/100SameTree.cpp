//1. Recursion. O(N)
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && q || p &&!q) return false;
        if(!p && !q) return true;
        if(p && q) return (p->val==q->val)&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
    }
};

//2. Iteration use one stack.
class Solution{
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode*> s;
        s.push(p);
        s.push(q);
        while(!s.empty()) {
            p = s.top(); s.pop();
            q = s.top(); s.pop();
            if (!p && !q) continue;
            if (!p || !q) return false;
            if (p->val != q->val) return false;
            s.push(p->left);
            s.push(q->left);
            s.push(p->right);
            s.push(q->right);
        }
        return true;
    }
};