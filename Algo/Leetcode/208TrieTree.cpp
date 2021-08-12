struct TrieNode{
    bool isEnd;
    struct TrieNode* ptr[26];
    TrieNode(bool e): isEnd(e) {
        memset(ptr, 0, sizeof(ptr));
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode(true);
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insert(root, word);
    }

    void insert(TrieNode* root, string word){
        int n = word.length();
        if(n==0) return;
        int idx = word[0] - 'a';
        if(!root->ptr[idx]) root->ptr[idx] = new TrieNode(false);
        if(n==1){
            root->ptr[idx]->isEnd = true;
            return;
        }
        insert(root->ptr[idx], word.substr(1));
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return search(root, word);
    }

    bool search(TrieNode* root, string word){
        int n = word.length();
        if(n==0) return root->isEnd;
        if(!root) return false;
        int idx = word[0] - 'a';
        if(!root->ptr[idx]) return false;
        return search(root->ptr[idx], word.substr(1));
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWith(root, prefix);
    }

    bool startsWith(TrieNode* root, string prefix) {
        int n = prefix.length();
        if(n==0) return true;
        if(!root) return false;
        int idx = prefix[0] - 'a';
        if(!root->ptr[idx]) return false;
        return startsWith(root->ptr[idx], prefix.substr(1));
    }

    TrieNode* root;
};