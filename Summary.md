# 常见算法题及数据结构总结

---
# 目录
#### [1.数组（Array）](#1)
#### [2.矩阵（Matrix）](#2)
#### [3.字符串（String）](#3)
#### [4.链表（LinkedList）](#4)
#### [5.树（Tree）](#5)
#### [6.栈（Stack）](#6)
#### [7.队列（Queue）](#7)
#### [8.堆（Heap）](#8)
#### [9.哈希表（HashTable）](#9)
#### [10.图（Graph）](#10)
#### [11.位运算（Bit Manipulation）](#11)
#### [12.动态规划（Dynamic Programming）](#12)
#### [xx.排序算法（Sorting）](#12)
---

# <h2 id="1">数组(Array)</h2>
### C++用法
```c++
int arr [5] = {1,2,3,4,5}             ## Init an array
int arr [] = {1,2,3,4,5}              ## Init an array without declare the length
arr[idx]                              ## acces the idx
int *ptr = arr                        ## init a pointer of array
```
```c++
array<int,3> arr {1,2,3}                                    ## Init an array
arr[idx]                                                    ## access the idx
sort(arr.begin(), arr.end())                                ## sort the array
for(auto s : arr) {}                                        ## loop through the array
array.size()                                                ## return the size
array.empty()                                               ## return whether the array is empty
```
```c++
vector<int> v {1,2,3}                                       ## init vector by value
vector<int> v(10)                                           ## init vector by length
vector<int> vec (arr, arr+(sizeof(arr)/sizeof(arr[0])) )    ## init by an array
vector<int> v1 (v2.begin(), v2.end())                       ## init by another vector
vec[idx]                                                    ## access the idx
vec.clear()                                                 ## clear the vector
vec.size()                                                  ## vector size
vec.push_back(10)                                           ## push back value at the end.
vec.front()                                                 ## return the first val
vec.back()                                                  ## return the last val
vec.pop_back()                                              ## remove the last val
vec.at(idx)                                                 ## access by index. same as vec[idx]
sort(vec.begin(), vec.end());                               ## sort the vector
    static bool comp(int a, int b)                          ## sort by self defined static cmp func
    sort(v.begin(), v.end(), comp)
vector<vector<int>> vec;                                    ## vector of vector(matrix), access by vec[i][j]
for (auto x : vec) {}                                       ## access by auto var though the vector
vector<int>::iterator it;                                   ## create iterator
    for(it=vec.begin(); it!=vec.end(); it++) {cout<<*it}    ## loop through using iterator, *it is the val
vec.insert(vec.begin()+i, x)                                ## insert x at i+1 pos
vec.erase(vec.begin()+i)                                    ## remove the i+i val
vec.erase(vec.begin()+i, vec.begin()+j)                     ## remove from i+1 to j
reverse(vec.begin(), vec.end())                             ## reverse the vector
```
### Python用法
```python
l = []                      ## Initial a empty list
l.append(ele)               ## Append an element into the list
l.extend(list)			 	## Combine two list
l.insert(i, x)			 	## insert x at pos i
l.remove(x)				 	## remove the first x
l.pop([i])				 	## pop and remove the i-th one (No specify will return the last)
l.index(x)				 	## return the first index of x
l.count(x)				 	## count the number of x
l.reverse()				 	## inplace reverse
l.sort()			      	## sort list
l.sort(cmp=lamba x,y: x-y)  ## sort by cmp (smaller first)
len(list)				 	## length
sum(list)				 	## sum of all elements
```

### 问题及思路
> 1. 旋转数组的最小数字 ([剑指offer Q6](https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba?tpId=13&tqId=11159&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 直接扫描，当后面小于前面则返回
	复杂度： O(1) space, O(n) time.
	
	方法2: 二分查找。每次对比mid与头尾的值。注意start一定大于等于end，否为不为旋转数组而是排序数组
	· mid == end && mid == start, 则查找[start+1, end-1] <--(注意[1,0,1,1,1]与[1,1,1,0,0]的特殊case)
	· mid>=start, 则查找[mid, end];
	· mid<=end,则查找[start, mid]
	复杂度： O(1) space, O(logn) time.

---
<br />

# <h2 id="2">矩阵(Matrix)</h2>
### C++用法
```c++
int arr[4][5] = {}						## init a empty matrix
arr[row][col]                           ## acces the idx
```
```c++
vector<vector<int>> v;                  ## init empty matrix
```
### Python用法
```python
arr = [[]]                      	    ## Initial a empty matrix
arr[row][col]                           ## acces the idx
```

### 问题及思路

> 1. 递增二维数组中的查找 ([剑指offer Q1](https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1))

	方法1: 从右上角开始判断，小了往下， 大了往左。
	复杂度： O(1) space, O(n) time.
> 


---
<br />

# <h2 id="3">字符串(String)</h2>
### C++用法
```c++
string s（“sss")                                             ## init string
s.length()                                                   ## length of string
s.substr(start, length)                                      ## substring from start with length
str.insert(pos, str2, start, length)                         ## insert at position with part of str2
str.erase(start, length)                                     ## erase from start with length
str.append(str2, start, length)                              ## append part of str2
str += str2                                                  ## same as appending
str.replace(start, length, str2, start2, length2)            ## replace part of str by part of str2
str.assign(base)                                             ## assign base to str
str.find(str2, start, length)                                ## find part of str2. Not found return string::npos
str.rfind(str2, start, length)                               ## find from right.
str.compare(start, length, str2, start2, length2)            ## compare part of str with part of str2
to_string(val)                                               ## val to string
stoi(str)                                                    ## string to int
stof(Str)                                                    ## string to float
```
### Python用法
```python
fields = s.split(" ")                ## Split the string into fields by " "(Can change to other delimiter)
'|'.join(list)                       ## Join the list separate by '|'. Like '1|2|3|4'
s.replace('a','b')                   ## Replace all 'a' into 'b'.
x in s                               ## Check whether x is in string s
s.strip('\n')                        ## Trim \n or other
s.capitalize()                       ## Change to upper cases
s.casefold()                         ## Change to lower cases
s.count('x')                         ## Count the number of x
endwith(str)                         ## Return whether s is endwith str
s.find(str)                          ## Find the first place of str in s
s.format()                           ## Format string({} place in string)
s.isalnum()                          ## string is all num or alpha
s.isalpha()                          ## string is all alpha
s.isdigit()                          ## string is all digits
s.islower()                          ## string is all lowercases
s.isspace()                          ## string is all whitespaces
s.isupper()                          ## string is all uppercases
```
### 问题及思路

> 1. 替代空格: " " -> "%20" ([剑指offer Q2](https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 扫描一遍计算空格个数，提前分配string，在扫描一遍双指针替换
	复杂度： O(n) time.
	
	方法2: python使用split(" ") 与 "%20".join()函数
	复杂度: O(n) time.
> 

---
<br />

# <h2 id="4">链表（LinkedList）</h2>
### C++用法
```c++
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
```
```c++
list<int> l                                                 ## init list
list<int>::iterator it                                      ## list iterator
l.back()                                                    ## last element
l.front()                                                   ## first element
l.erase(iter)                                               ## erase a node by iter
l.pop_back()                                                ## pop the last node out
l.pop_front()                                               ## pop the first out
l.push_front(3)                                             ## push back a node
l.push_back(4)                                              ## push a node at front
l.sort()                                                    ## sort the list
l.unique()                                                  ## remove duplicate
l.size()                                                    ## return size
l.empty()                                                   ## check empty
l.assign(1,2,3)                                             ## assign value
l.assign(l2.begin(), l2.end())                              ## assign value by other list
l.assign(array, array+3)                                    ## assign value by arr[]
l.insert(it, 2, 3)                                          ## insert at iter for some values
l.reverse()                                                 ## reverse list
l.remove(target)                                            ## remove the target number
l.merge(l2)                                                 ## merge two sorted list
```
### Python用法
```python
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
```

### 问题及思路

> 1. 从尾到头返回链表的值 ([剑指offer Q3](https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 反转链表再返回
	复杂度： O(1) space, O(n) time.
	
	方法2: 用额外的stack储存，再返回
	复杂度： O(n) space, O(n) time.
	
---
<br />

# <h2 id="5">树（Tree)</h2>
### 知识
- 常见有二叉树，二叉搜索树，二叉平衡树，红黑树等等
- 前序遍历 (根节点 -> 左子树 -> 右子树)
- 中序遍历 (左子树 -> 根节点 -> 右子树) -- 搜索树的排序
- 后序遍历 (左子树 -> 右子树 -> 根节点)
- 层级遍历
- 深度优先与广度优先

### C++用法
```c++
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
```
### Python用法
```python
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
```

### 问题及思路

> 1. 从前序遍历与中序遍历结果重建二叉树 ([剑指offer Q4](https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 前序遍历数组[根结点，左子树节点，右子树节点] && 中序遍历数组[左子树节点，根结点，右子树节点]
		于是通过前序的第一个root，将中序分隔开来，递归重建左右子树
	复杂度： O(1) space, O(n) time.
---
<br />


# <h2 id="6">栈（Stack）</h2>
### C++用法
```c++
stack.push(x)                                               ## push a value at top
stack.pop()                                                 ## pop the top value, will not return
stack.top()                                                 ## return the top value
stack.size()                                                ## return the size
stack.empty()                                               ## return whether the queue is empty
```
### Python用法
```python
- List as Stack
    stack = [...]            ## Init a stack. Last item is like the top of stack
    stack.append(7)          ## Add to last
    stack.pop()              ## Pop the last
```

### 问题及思路

> 1. 两个栈实现队列 ([剑指offer Q5](https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 往stack1中push; pop时如果stack2为空，先将stack1从顶pop过来，然后返回stack2的top，不为空则直接返回

---
<br />

# <h2 id="7">队列（Queue）</h2>
### C++用法
```c++
queue.push(x)                                               ## push a value at back
queue.pop()                                                 ## pop the first value (FIFO), will not return value
queue.front()                                               ## return the first value
queue.back()                                                ## return the last value
q.empty()                                                   ## return whether the queue is empty
q.size()                                                    ## return the size
```
### Python用法
```python
- List as Queue
    queue = []               ## Init a queue. New items will be at later pos.
    queue.append(a)          ## Add to last
    queue.pop(0)             ## Pop the first (oldest) -- This is slow because it needs to move all.
```
```python
- from collections import deque
    queue = deque([a,b,c])   ## Init a queue
    queue.append(d)          ## Add to last
    queue.popleft()          ## Pop the oldest
```
### 问题及思路

> 1. 

	方法1: 
---
<br />


# <h2 id="8">堆（Heap)</h2>
### C++用法
```c++
-- (operation on vector) --
make_heap(vec.begin(), vec.end())                           ## make the heap to be the max heap. 'greater<int>()' as last argument turn it to min heap.
vec.front()                                                 ## get the first val(max) from max heap
vec.push_back(40); push_heap(vec.begin(), vec.end())        ## push a value
pop_heap(v.begin(), v.end()); v.pop_back()                  ## remove the max
sort_heap(v.begin(), v.end());                              ## need to sort heap after pop_back()
```
```c++
priority_queue<int> q(vec.begin(),vec.end());               ## max heap
priority_queue<int, vector<int>, greater<int> >q;           ## min heap. Can init by q(vec.begin(),vec.end())
q.pop()                                                     ## pop the heap's top
q.top()                                                     ## get the heap's top
q.push(val)                                                 ## push value
```
### Python用法
```python
-package [heapq]
    h = []                           ## init
    heappush(h, val)                 ## push val to heap h
    heappop(h)                       ## pop the min and return
    heapify(a)                       ## build min heap from list a
    _heapify_max(a)                  ## build max heap from list a
    _heappop_max(a)                  ## pop for max heap
    _heappush_max(a, val)            ## push for max heap
```

### 问题及思路

> 1. 

	方法1: 
---
<br />


# <h2 id="9">哈希表（HashTable）</h2>
### C++用法
```c++
map<int, int> m;                                            ## init a map, with key-value specify
m[1] = 10                                                   ## assign value
map.insert({key, val})                                      ## insert value
map.insert(pair<int,int>(3,3))                              ## insert by specify a pair
map.insert(m2.begin(), m2.end())                            ## insert by copying map2
map<int,int>::iterator it;                                  ## iterator
    it -> first                                             ## iter -> key
    it -> second                                            ## iter -> val
map.size()                                                  ## number of pairs in map
map.empty()                                                 ## whether map is empty
map.find(key)                                               ## return an iterator。 return map.end() is not found
map.count(key)                                              ## number of times key appear
map.erase(key)                                              ## remove pair by key
map.erase(map.find(key))                                    ## remove pair by iterator
iter = map.equal_range(key)                                 ## equal range finder
    iter.first -> first/second                              ## lower bound (not bigger than key)
    iter.second -> first/second                             ## upper bound (first bigger than key)
```
```c++
unordered_map<int, int> m;                                  ## init. Other methods are the same as map
```
```c++
unordered_multimap<int, pair<int, int>> map;                ## one key with two values
unordered_multimap<int, tuple<int, int, int>> map;          ## one key with multiple values
map.insert(make_pair(key, make_pair(v1, v2)));              ## insert value
iter -> first                                               ## get key from iterator
iter -> second.first                                        ## get first val in pair from iterator
iter -> second.second                                       ## get second val in pair from iterator
```
### Python用法
```python
s = {'a':1, 'b':2}                   ## Init a dict
s.keys()                             ## list all keys
s.values()                           ## list all values
s.items()                            ## list all k-v pairs
s.get(key)                           ## get the value from a key
s.pop(key)                           ## remove key
s.popitem()                          ## remove the last item
```

### 问题及思路

> 1. 

	方法1: 
---
<br />


# <h2 id="10">图（Graph）</h2>
### C++用法
```c++

```
### Python用法
```python

```

### 问题及思路

> 1. 
	
	方法1: 
---
<br />

# <h2 id="11">位运算（Bit Manipulation）</h2>
### C++用法
```c++
	>>			 ## Shfit right(add the leftmost bit of original)
	<<			 ## Shift left(positive add 0, negative needs more steps). Exceed will change to Long(64 bits)
	|            ## OR
	&			 ## And
	^			 ## Exclusive OR
	~			 ## NOT
```
### Python用法
```python
0b111			 ## 0b tells following are binary
	bin(int)     ## Tells the binary code of an int
	>>			 ## Shfit right(add the leftmost bit of original)
	<<			 ## Shift left(positive add 0, negative needs more steps). Exceed will change to Long(64 bits)
	|            ## OR
	&			 ## And
	^			 ## Exclusive OR
	~			 ## NOT
```
```python
from bitarray import bitarray
	- a = bitarray(10)		 ## Init bitarray
	- a[2:5] = 1			 ## Set some bits
	- a.all()			 ## return if all are 1
```

### 问题及思路

> 1. 二进制中的1的个数 ([剑指offer Q11](https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: for loop 查看每一位的是否为1
	复杂度： O(1) space, O(1) time.

---
<br />


# <h2 id="12">动态规划（Dynamic Programming）</h2>
### 问题及思路

> 1. 斐波拉契数列 ([剑指offer Q7](https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: for loop 动态计算后面的值，注意溢出，long long保存结果
	复杂度： O(1) space, O(n) time.
	相关： 青蛙跳， 矩形覆盖


---
<br />




# <h2 id="0">Template</h2>
### C++用法
```c++

```
### Python用法
```python

```

### 问题及思路

> 1. 
	
	方法1: 
---
<br />






