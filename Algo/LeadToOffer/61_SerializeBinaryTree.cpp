//1. Recursive. But also use istringsteam, ostringsteam.
class Solution {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();

    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode* root, ostringstream &out){
        if(root){
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }else
            out << "null ";
    }

    TreeNode* deserialize(istringstream &in){
        string val;
        in >> val;
        if(val == "null") return NULL;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
