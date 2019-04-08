class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        
        TreeLinkNode dummy(-1);  //Dummy next is always the first node in the needed connect level.
        for(TreeLinkNode *curr = root, *prev = &dummy; curr; curr = curr->next){
            if(curr->left){
                prev -> next = curr -> left;
                prev = prev -> next;
            }            
            if(curr->right){
                prev -> next = curr->right;
                prev = prev -> next;
            }
        }
        connect(dummy.next);
    }
};