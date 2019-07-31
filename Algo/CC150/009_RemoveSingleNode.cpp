//1.copy value and remove next
class Remove {
public:
    bool removeNode(ListNode* pNode) {
        if (!pNode)
            return true;
        if(!pNode->next)
            return false;
        pNode->val = pNode->next->val;
        pNode->next = pNode->next->next;
        return true;
    }
};
