class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* tmp;
        Node* move = head;
        if (!head) return NULL;
        while(move){
            tmp = new Node(move->val);
            tmp->next = move->next;
            move->next = tmp;
            move = move->next->next;
        }
        move = head;
        while(move){
            if(move->random)
                move->next->random = move->random->next;
            move = move->next->next;
        }
        move = head;
        Node* res = move->next;
        tmp = res;
        while(tmp->next){ //check the condition
            move->next = move->next->next;
            tmp->next = tmp->next->next;
            move = move->next;
            tmp = tmp->next;
        }
        move->next = NULL;  //remember to change
        return res;
    }
};