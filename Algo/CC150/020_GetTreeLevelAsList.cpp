class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        if (dep<=0 || !root)
            return NULL;
        queue<TreeNode*> level;
        level.push(root);
        while(!level.empty()) {
            dep--;
            if (dep==0) {
                ListNode* res = new ListNode(level.front()->val);
                ListNode* res_head = res;
                level.pop();
                while(!level.empty()) {
                    res->next = new ListNode(level.front()->val);
                    res = res -> next;
                    level.pop();
                }
                return res_head;
            }
            int count = level.size();
            while(count!=0) {
                TreeNode* temp = level.front();
                level.pop();
                if (temp->left)
                    level.push(temp->left);
                if (temp->right)
                    level.push(temp->right);
                count--;
            }
        }
        return NULL;
    }
};
