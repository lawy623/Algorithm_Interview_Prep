// prefix + tree
class Solution {
public:
    map<int, int> preSum;
    int res;
    int pathSum(TreeNode* root, int targetSum) {
        preSum[0] = 1;
        dfs(root, targetSum, 0);
        return res;
    }

    void dfs(TreeNode* root, int targetSum, int sum){
        if(!root) return;

        sum += root->val;
        if(preSum.find(sum - targetSum) != preSum.end()) res += preSum[sum - targetSum];
        preSum[sum]++;
        dfs(root->left, targetSum, sum);
        dfs(root->right, targetSum, sum);
        preSum[sum]--;
        sum -= root->val;
    }
};