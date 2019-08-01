// 1. Use vector to store the inorder search, and find the next val.
class Successor {
public:
    void inorder(TreeNode* root, vector<int> &res) {
        if (!root)
            return;
        if (root->left)
            inorder(root->left, res);
        res.push_back(root->val);
        if (root->right)
            inorder(root->right, res);
        return;
    }
    int findSucc(TreeNode* root, int p) {
        vector<int> in;
        inorder(root, in);
        for (int i=0; i<in.size(); i++) {
            if (in[i]==p && i<in.size()-1)
                return in[i+1];
        }
        return -1;
    }
};

// 2. Use stack
class Successor {
public:
    int findSucc(TreeNode* root, int p) {
        if (!root)
            return -1;
        stack<TreeNode*> s;
        bool find = false;
        while(!s.empty() || root) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                if (find)
                    return root->val;
                if (root->val == p)
                    find = true;
                s.pop();
                root = root->right;
            }
        }
        return -1;
    }
};


// 3. Use a indicator to find it recursively.
class Successor {
public:
    int findSucc(TreeNode* root, int p) {
        bool sign=0;
        return findSucc1(root,p,sign);
    }
    int findSucc1(TreeNode* root,int p,bool &sign)
    {
        if(root==NULL)
            return -1;
        int left=findSucc1(root->left,p,sign);
        if(left!=-1)
            return left;
        if(sign==true)
            return root->val;
        if(root->val==p)
            sign=true;
        return findSucc1(root->right,p,sign);
    }
};
