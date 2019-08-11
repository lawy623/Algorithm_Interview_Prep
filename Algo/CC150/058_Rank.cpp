// 1. Brute force. O(n^2)
class Rank {
public:
    vector<int> getRankOfNumber(vector<int> A, int n) {
        vector<int> res;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<i; j++){
                if (A[j]<A[i])
                    count++;
            }
            res.push_back(count);
        }
        return res;
    }
};

// Use Tree
class Rank {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    void insert(TreeNode* root, int val) {
       if (val>=root->val) {
           if (!root->right)
               root->right = new TreeNode(val);
           else
               insert(root->right, val);
       } else {
           if (!root->left)
               root->left = new TreeNode(val);
           else
               insert(root->left, val);
       }
    }
    int countRank(TreeNode* root, int val) {
        if (!root)
            return 0;
        if (root->val==val)
            return countRank(root->left, val);
        else if (root->val > val) {
                return countRank(root->left, val);
        } else {
                return countRank(root->left, val) + 1 + countRank(root->right, val);
        }
    }
    vector<int> getRankOfNumber(vector<int> A, int n) {
        vector<int> res;
        TreeNode* root = new TreeNode(A[0]);
        res.push_back(0);
        for(int i=1; i<n; i++){
            insert(root, A[i]);
            res.push_back(countRank(root, A[i]));
        }
        return res;
    }
};
