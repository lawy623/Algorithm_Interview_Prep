/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return NULL;
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* buildTree(vector<int>& preorder, int p_in, int p_out, vector<int>& inorder, int i_in, int i_out){
        if (p_in > p_out)
            return NULL;

        if (p_in == p_out){
            TreeNode* root = new TreeNode(preorder[p_in]);
            return root;
        }

        TreeNode* root = new TreeNode(preorder[p_in]);
        int root_pos = findRoot(inorder, i_in, i_out, root->val);
        int left_len = root_pos - i_in;
        int right_len = i_out - root_pos;

        if(left_len > 0)
            root->left = buildTree(preorder, p_in+1, p_in+left_len, inorder, i_in, root_pos-1);
        if(right_len > 0)
            root->right = buildTree(preorder, p_in+left_len+1, p_out, inorder, root_pos+1, i_out);

        return root;
    }

    int findRoot(vector<int>& inorder, int i_in, int i_out, int val){
        for(int i=i_in; i<=i_out; i++){
            if(inorder[i] == val)
                return i;
        }
        return -1;
    }
};
