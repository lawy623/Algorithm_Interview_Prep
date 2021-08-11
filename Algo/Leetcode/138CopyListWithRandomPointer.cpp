// Use a hash table
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        map<Node*, Node*> m;
        Node* move = head;
        Node* new_head = new Node(0);
        Node* tmp = new_head;
        while(move){
            tmp->next = new Node(move->val);
            tmp = tmp->next;
            m[move] = tmp;
            move = move->next;
        }
        move = head;
        tmp = new_head->next;
        while(move){
            tmp->random = m[move->random];
            move = move->next;
            tmp = tmp->next;
        }
        return new_head->next;
    }
};

// In place copy and split
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