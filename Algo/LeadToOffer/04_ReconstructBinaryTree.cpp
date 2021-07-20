//1. cpp. Recursive. O(1) space.
class Solution {
public:
    int findValInVec(vector<int> vec, int start, int end, int target) {
      if(vec.size()==0 || start>end )
          return 0;
        int idx = start;
        while(idx <= end){
            if(vec[idx]==target)
                return idx;
            idx++;
        }
        return 0;
    }

    TreeNode* reConstruct(vector<int> pre, int pre_start, int pre_end, vector<int> vin, int vin_start, int vin_end) {
        int root_val = pre[pre_start];

        TreeNode* root = new TreeNode(root_val);
        int idx = findValInVec(vin, vin_start, vin_end, root_val);
        int left_length = idx - vin_start;
        int right_length = vin_end - idx;

        if (left_length!=0)
            root->left = reConstruct(pre, pre_start+1, pre_start+left_length, vin, vin_start, idx-1);

        if (right_length!=0)
            root->right = reConstruct(pre, pre_start+left_length+1, pre_end, vin, idx+1, vin_end);

        return root;
    }

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size()==0 || vin.size()==0)
            return NULL;

        TreeNode* root = reConstruct(pre, 0, pre.size()-1, vin, 0, vin.size()-1 );
        return root;
    }
};
