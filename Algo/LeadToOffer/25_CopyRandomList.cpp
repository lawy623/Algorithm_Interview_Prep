// 1. Use map. O(n) time. O(n) space. keep track of the two lists' position.
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* move_head = pHead;
        if (!pHead)
            return NULL;
        unordered_map<RandomListNode*, RandomListNode*> list_to_list;

        RandomListNode* result_head = new RandomListNode(pHead->label);
        RandomListNode* result_move_head = result_head;
        list_to_list.insert(make_pair(move_head, result_move_head));

        move_head = move_head->next;

        while(move_head) {
            result_move_head->next = new RandomListNode(move_head->label);
            result_move_head = result_move_head->next;
            list_to_list.insert(make_pair(move_head, result_move_head));
            move_head = move_head->next;
        }

        move_head = pHead;
        result_move_head = result_head;
        while(move_head) {
            if (move_head->random)
                result_move_head->random = list_to_list[move_head->random];
            move_head = move_head->next;
            result_move_head = result_move_head->next;
        }
        return result_head;
    }
};

// 2. Copy first then split. O(n) time, o(1) extra space
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        RandomListNode* move_head = pHead;
        if (!pHead)
            return NULL;
        //1. copy each to the back
        RandomListNode* temp = pHead;
        while(move_head) {
            temp = move_head->next;
            move_head->next = new RandomListNode(move_head->label);
            move_head->next->next = temp;
            move_head = move_head ->next ->next;
        }
        //2. link the next random to this random's next
        move_head = pHead;
        while(move_head) {
            if (move_head->random)
                move_head->next->random = move_head->random->next;
            move_head = move_head->next->next;
        }
        //3.split two lists
        move_head = pHead;
        RandomListNode* res_head = move_head->next;
        RandomListNode* res_move_head = move_head->next;
        move_head->next = move_head->next->next;
        move_head = move_head->next;

        while(move_head) {
            res_move_head->next = move_head->next;
            res_move_head = res_move_head->next;
            move_head->next = move_head->next->next;
            move_head = move_head->next;
        }

        return res_head;
    }
};
