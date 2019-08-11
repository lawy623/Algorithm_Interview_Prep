// 1. Inorder search
class Converter {
public:
    ListNode* treeToList(TreeNode* root) {
        ListNode* res = new ListNode(0);
        ListNode* resHead = res;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(!s.empty() || p) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                res->next = new ListNode(p->val);
                res = res->next;
                s.pop();
                p = p->right;
            }
        }
        return resHead->next;
    }
};

// 2. Struct the double linkedlist
struct TopEnd {
    struct ListNode *top;
    struct ListNode *end;
    TopEnd() : top(NULL), end(NULL) {}
};
class Converter {
public:
    TopEnd* toList(TreeNode* root) {
        if (!root)
            return NULL;
        TopEnd* left = toList(root->left);
        TopEnd* right = toList(root->right);
        TopEnd* l = new TopEnd();
        if (left) {
            l->top = left->top;
            left->end->next = new ListNode(root->val);
            left->end = left->end->next;
        } else {
            l->top = new ListNode(root->val);
            left = new TopEnd();
            left->top = l->top;
            left->end = l->top;
        }
        if (right) {
            l->end = right->end;
            left->end->next = right->top;
        } else {
            l->end = left->end;
        }
        return l;
    }
    ListNode* treeToList(TreeNode* root) {
        TopEnd* l = toList(root);
        return l->top;
    }
};
