class Solution {
public:
    struct TopEndNode {
        struct TreeNode* top;
        struct TreeNode* end;
        TopEndNode(): top(NULL), end(NULL) {}
    };

    TopEndNode* ConvertNode(TreeNode* pRootOfTree) {
        TopEndNode* res = new TopEndNode();
        if (!pRootOfTree)
            return res;

        TopEndNode* list_left = ConvertNode(pRootOfTree->left);
        TopEndNode* list_right = ConvertNode(pRootOfTree->right);
        if (list_left->end) {
            list_left->end->right = pRootOfTree;
            pRootOfTree->left = list_left->end;
        } else
            list_left->top = pRootOfTree;

        if (list_right->top) {
            list_right->top->left = pRootOfTree;
            pRootOfTree->right = list_right->top;
        } else
            list_right->end = pRootOfTree;

        res->top = list_left->top;
        res->end = list_right->end;

        return res;
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree)
            return NULL;

        TopEndNode* res = ConvertNode(pRootOfTree);

        return res->top;
    }
};

// dfs
class Solution {
public:
    Node *pre, *head;
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return NULL;
        dfs(root);
        head->left=pre;
        pre->right=head;
        return head;
    }

    void dfs(Node* cur){
        if(cur==NULL) return;
        dfs(cur->left);
        if(pre!=NULL) pre->right=cur;
        else head=cur;
        cur->left=pre;
        pre=cur;
        dfs(cur->right);
    }
};