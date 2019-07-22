class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (!pNode)
            return NULL;
        if (pNode->right) {
            pNode = pNode->right;
            while(pNode->left)
                pNode = pNode->left;
            return pNode;
        }
        while (pNode->next!=NULL) {
            if (pNode->next->left==pNode)
                return pNode->next;
            pNode = pNode->next;
        }
        return NULL;
    }
};
