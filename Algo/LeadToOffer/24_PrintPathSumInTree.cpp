class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > paths;
        if (!root)
            return paths;

        if (!root->left && !root->right && root->val == expectNumber) {
            vector<int> single;
            single.push_back(expectNumber);
            paths.push_back(single);
        }

        vector<vector<int> > temp;
        vector<int> vec;
        if (root->left) {
            temp = FindPath(root->left, expectNumber - root->val);
            if (temp.size()!=0 && temp[0].size()!=0) {
                for(int i=0; i<temp.size(); i++){
                    vec = temp[i];
                    vec.insert(vec.begin(), root->val);
                    paths.push_back(vec);
                    vec.clear();
                }
            }
        }
        if (root->right) {
            temp = FindPath(root->right, expectNumber - root->val);
            if (temp.size()!=0 && temp[0].size()!=0) {
               for(int i=0; i<temp.size(); i++){
                    vec = temp[i];
                    vec.insert(vec.begin(), root->val);
                    paths.push_back(vec);
                    vec.clear();
                }
            }
        }

        return paths;
    }
};
