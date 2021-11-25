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



// string
#include <string>

string s;  // whole line with string
getline(cin, s);
cout << s << endl;

char ch[1000];
cin >> ch;    // line break with space (e.g. screff 10, you need both string and num)
string s = ch;
cout << s << " " << s.length() << endl;


// STDC++ Lib
#include <bits/stdc++.h>

cout << INT_MAX << INT_MIN << endl;
sort(nums.begin(), nums.end());


// class
class Solution {
public:
    Solution(vector<int> nums){
        //TODO Init
    }

    void method1(){
        //Implement m1
    }

    void method2(){
        //Implement m2
    }

private:
    vector<int> priNums;
};

Solution s = Solution([1, 2, 3]);  // 在栈中初始, 如果对象太大， 容易stack overflow
s.method1();

Solution* s = new Solution([1, 2, 3]);  // 在堆中初始， 适合大对象， 要记得delete
s -> method2();
delete s;


// math (log, ceil, floor)
#include <math.h>

int x = ceil(log(10) / log(4));