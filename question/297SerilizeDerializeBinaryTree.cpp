//1. Works But memory exceeds.
class Codec {
public:

    string addString(string s, TreeNode* t){
        if(!t)
            s.append("null");
        else
            s.append(to_string(t->val));
        
        s += ',';
        
        return s;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)
            return "[null]";
        
        string res = "";
        res += '[';
        res = addString(res, root);
        q.push(root);
        
        while(!q.empty()){
            TreeNode* last = q.front();
            q.pop();
            if(last->left)
                q.push(last->left);
            if(last->right)
                q.push(last->right);
            
            res = addString(res, last->left);
            res = addString(res, last->right);
        }
        
        res = res.substr(0,res.length()-1);
        res += ']';
        
        return res;
    }
    //Get the first comma or ']' after start index.
    int get_comma(string s, int start){
        for(int i=start;i<s.length();i++){
            if(s[i]==',' || s[i]==']')
                return i;
        }
        return start;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="[null]")
            return NULL;
        
        data = data.substr(1,data.length()-1);
        int l = get_comma(data,0);
        string s = data.substr(0,l);
        
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(s));
        q.push(root);
        int start = l;
        int next1 = 0;
        int next2 = 0;
        while(!q.empty()){
            next1 = get_comma(data,start+1);
            string left = data.substr(start+1, next1-start-1);
            next2 = get_comma(data,next1+1);
            string right = data.substr(next1+1,next2-next1-1);
            start = next2;
            if(left!="null"){
                TreeNode* t1 = new TreeNode(stoi(left));
                q.front()->left = t1;
                q.push(t1);
            }
            if(right!="null"){
                TreeNode* t2 = new TreeNode(stoi(right));
                q.front()->right = t2;
                q.push(t2);
            }
            q.pop();
        }
        return root;
    }
};

//2. Same But use in/out stream.
//Good thing here is to learn to use the istringstream/ostringstream.
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (t) {
                out << t->val << ' ';
                q.push(t->left);
                q.push(t->right);
            } else {
                out << "# ";
            }
        }
        return out.str();
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        istringstream in(data);
        queue<TreeNode*> q;
        string val;
        in >> val;
        TreeNode *res = new TreeNode(stoi(val)), *cur = res;
        q.push(cur);
        while (!q.empty()) {
            TreeNode *t = q.front(); q.pop();
            if (!(in >> val)) break;
            if (val != "#") {
                cur = new TreeNode(stoi(val));
                q.push(cur);
                t->left = cur;
            }
            if (!(in >> val)) break;
            if (val != "#") {
                cur = new TreeNode(stoi(val));
                q.push(cur);
                t->right = cur;
            }
        }
        return res;
    }
};

//3. Recursive. But also use istringsteam, ostringsteam.
class Codec {
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
