//1. Recusion. O(N)
class Solution {
public:
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root){
        if(!root) return;

        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
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