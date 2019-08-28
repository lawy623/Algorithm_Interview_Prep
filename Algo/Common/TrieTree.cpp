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
