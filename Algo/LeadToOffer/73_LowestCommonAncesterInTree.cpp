// dfs, get all paths first and find
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> p1;
        vector<int> p2;
        vector<int> tmp;

        dfs(root, p1, tmp, p);
        while(!tmp.empty())
            tmp.pop_back();
        dfs(root, p2, tmp, q);

        int i=0;
        while(i < min(p1.size(), p2.size())){
            if(p1[i] == p2[i])
                i++;
            else
                break;
        }

        TreeNode* res = new TreeNode(p1[i-1]);
        return res;
    }

    void dfs(TreeNode* root, vector<int>& p, vector<int>& tmp, TreeNode* target){
        if(!root)
            return;

        tmp.push_back(root->val);
        if(root == target){
            for(auto m:tmp)
                p.push_back(m);
            return;
        }
        dfs(root->left, p, tmp, target);
        dfs(root->right, p, tmp, target);
        tmp.pop_back();
    }
};

// recursive
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p|| root==q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        return left==NULL? right:left;
    }
};