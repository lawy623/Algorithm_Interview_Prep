//1. Recusion. O(N)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        preorderTraversal(root,res);
        return res;
    }
    
    void preorderTraversal(TreeNode* root, vector<int>& res){
        if(!root) return;
        
        res.push_back(root->val);
        preorderTraversal(root->left,res);
        preorderTraversal(root->right,res);
    }
};

//2. Use stack and iteratively. O(N)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode *> s;
        
        TreeNode *p = root;
        
        while(!s.empty() || p){
            if(p){
                res.push_back(p->val);
                s.push(p);
                p = p->left;
            }
            else{
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
        return res;
    }
};