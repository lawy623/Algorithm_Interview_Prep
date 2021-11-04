// includes
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// main func
int main(){
    // todo
    return 0;
}

// get vector
int n;
cin >> n;
vector<int> nums(n);  //Always remember to init with correct size. Otherwise overflow
for(int i=0; i<n; i++)
    cin >> nums[i];

//print vector
int n = nums.size();
cout << "Vector size " << n << endl;
for(int i=0; i<n; i++)
    cout << nums[i] << " ";
cout << endl;



// linked list
struct ListNode{
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* p) : val(x), next(p){}
};

// construct list from vector
ListNode* vec2List(vector<int> nums){
	ListNode* start = new ListNode(-1);
	ListNode* next = start;
	for(int i:nums){
		next->next = new ListNode(i);
		next = next->next;
	}
	return start->next;
}

// print list
void printList(ListNode* p){
	cout << "print List" << endl;
	ListNode* move = p;
	while(move){
		cout << move->val << " ";
		move = move->next;
	}
	cout << endl;
}