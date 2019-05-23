//1. Use Queue. Iteration. O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode *> q;
        
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i=0;i<size;i++){
                level.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res.push_back(level);
        }
        return res;
    }
};

//2. Recursion. O(N).
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        levelOrder(root,1,res);
        return res;
    }        
    void levelOrder(TreeNode* root,int level, vector<vector<int>>& res){
        if(!root) return;
        
        if(level>res.size()) res.push_back(vector<int>());
        
        res[level-1].push_back(root->val);
        levelOrder(root->left,level+1,res);
        levelOrder(root->right,level+1,res);
    }
};