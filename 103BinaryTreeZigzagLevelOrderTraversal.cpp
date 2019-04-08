//1. Keep a bool zigzag value to see whether move l-r or r-l.
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode *> nodes;
        nodes.push(root);
        bool zigzag = true;
        while(!nodes.empty()){
            vector<int> level;
            int len = nodes.size();
            for(int i=0;i<len;i++){
                level.push_back(nodes.front()->val);
                if(nodes.front()->left) nodes.push(nodes.front()->left);
                if(nodes.front()->right) nodes.push(nodes.front()->right);
                nodes.pop();
            }
            if(!zigzag) reverse(level.begin(),level.end());
            res.push_back(level);
            zigzag = !zigzag;
        }
        return res;
    }
};

//2. Iteration
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        zigzagLevelOrder(root,1,res,true);
        return res;
    }
    
    void zigzagLevelOrder(TreeNode* root, int level, vector<vector<int>>& res, bool zigzag) {
        if(!root) return;
        
        if(level>res.size()) res.push_back(vector<int>());
        
        if(zigzag) res[level-1].push_back(root->val);
        else res[level-1].insert(res[level-1].begin(),root->val);
        
        zigzagLevelOrder(root->left,level+1,res,!zigzag);
        zigzagLevelOrder(root->right,level+1,res,!zigzag);
        
        
    }
};