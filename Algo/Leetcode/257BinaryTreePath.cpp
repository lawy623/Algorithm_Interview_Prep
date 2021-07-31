// dfs trackback
class Solution {
public:
    vector<string> v;
    string s;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return v;
        dfs(root);
        return v;
    }

    void dfs(TreeNode* root){
        if(!root) return;
        string t = "->" + to_string(root->val);
        s += t;

        if(!root->left && !root->right)
            v.push_back(s.substr(2));

        dfs(root->left);
        dfs(root->right);
        s = s.substr(0, s.length()-t.length());
    }
};