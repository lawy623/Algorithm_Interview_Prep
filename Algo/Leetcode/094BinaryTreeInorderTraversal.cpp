//1. Recursion. O(N)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        inorderTraversal(root,res);
        return res;
    }
    
    void inorderTraversal(TreeNode* root, vector<int>& res) {
        if(!root) return;
        
        if(root->left) inorderTraversal(root->left,res);
        res.push_back(root->val);
        if(root->right) inorderTraversal(root->right,res);    
    }
};

//2. Use stack, do it iteratively. O(N)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<const TreeNode *> s;
        const TreeNode *p = root;
        
        while(!s.empty() || p){
            if(p){
                s.push(p);
                p = p->left;
            }else{
                p = s.top();
                s.pop();
                res.push_back(p->val);
                p = p->right;
            }
        }
        return res;
    }
};

//dfs
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return res;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
};