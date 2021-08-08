// recursive
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int l, int r){
        if(r<l) return vector<TreeNode*>{NULL};

        if(l==r){
            TreeNode* t = new TreeNode(l);
            return vector<TreeNode*>{t};
        }

        vector<TreeNode*> res;
        for(int i=l; i<=r; i++){
            vector<TreeNode*> lTrees = generateTrees(l, i-1);
            vector<TreeNode*> rTrees = generateTrees(i+1, r);
            for(auto a:lTrees){
                for(auto b:rTrees){
                    TreeNode* head = new TreeNode(i);
                    head->left = a;
                    head->right = b;
                    res.push_back(head);
                }
            }
        }
        return res;
    }
};