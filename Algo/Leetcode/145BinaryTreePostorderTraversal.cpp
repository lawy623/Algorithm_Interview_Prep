//1. Recursion. O(n).
class Solution {
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        dfs(root);
        return res;
    }

    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->left);
        dfs(root->right);
        res.push_back(root->val);
    }
};


//Iteratively. Use a pointer q to store the previous visited node. O(N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode *> s;
        TreeNode* p = root, *q = nullptr;
        
        do{
            while(p){
                s.push(p);
                p = p->left;
            }
            q = nullptr;
            while(!s.empty()){
                p = s.top();
                s.pop();
                if(p->right == q){
                    res.push_back(p->val);
                    q = p;
                }
                else{
                    s.push(p);
                    p = p->right;
                    break;
                }
            }
        }while(!s.empty());
        
        return res;
    }
};