// store the last value and counts. Update by dfs.
class Solution {
public:
    int max_count = 0;
    vector<int> res;
    int count = 0;
    TreeNode* pre = NULL;
    int last_val = 0;
    vector<int> findMode(TreeNode* root) {
        if(!root) return res;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* cur){
        if(!cur) return;

        dfs(cur->left);
        if(!pre){
            last_val = cur->val;
            pre = cur;
            max_count = 1;
            count = 1;
            res.push_back(cur->val);
        } else{
            if(cur->val == last_val) count += 1;
            else count = 1;
            last_val = cur->val;
            if(count == max_count) res.push_back(cur->val);
            else if(count > max_count){
                while(!res.empty()) res.pop_back();
                res.push_back(cur->val);
            }
            max_count = max(max_count, count);
        }
        pre = cur;
        dfs(cur->right);
    }
};