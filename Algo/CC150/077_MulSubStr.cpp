// 1. Use string find for each
class Substr {
public:
    vector<bool> chkSubStr(vector<string> p, int n, string s) {
        vector<bool> res;
        for(int i=0; i<n; i++) {
            if (s.find(p[i])!=-1)
                res.push_back(true);
            else
                res.push_back(false);
        }
        return res;
    }
};


// Trie Tree. You store all the suffix to TrieTree. The substr must be in the trieTree.
class Substr {
public:
    struct TrieNode {
        char c;
        struct TrieNode* ptr[26];
        TrieNode(char c): c(c) {
            memset(ptr, 0, sizeof(ptr));
        }
    };
    void insert(TrieNode* root, string str) {
        if (!root)
            return;
        int n = str.length();
        if (n==0)
            return;
        int idx = str[0]-'a';
        if (!root->ptr[idx])
            root->ptr[idx] = new TrieNode(str[0]);
        if (n==1)
            return;
        insert(root->ptr[idx], str.substr(1));
    }
    bool search(TrieNode* root, string str) {
        int n = str.length();
        if (n==0)
            return true;
        if (!root)
            return false;
        int idx = str[0]-'a';
        return root->ptr[idx]!=NULL && search(root->ptr[idx], str.substr(1));
    }
    vector<bool> chkSubStr(vector<string> p, int n, string s) {
        int len = s.length();
        TrieNode* root = new TrieNode(' ');
        for (int i=0; i<len; i++) {
            insert(root, s.substr(i));
        }
        vector<bool> res;
        for(int i=0; i<n; i++)
            res.push_back(search(root, p[i]));
        return res;
    }
};
