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
#### [13.数值计算（Numerical Calculation）](#13)
#### [14.贪心算法（Greedy Algorithm）](#14)
#### [15.排序算法（Sorting）](#15)
#### [16.大数据问题（Big Data）](#16)
#### [17.其他（Other）](#17)
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
	
> 2.调整数组顺序使奇数位于偶数前面 ([剑指offer Q13](https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 直接扫描，分别保存奇数与偶数数组，再合并
	复杂度： O(n) space, O(n) time.
	
	方法2: 冒泡排序的方法，每次前为偶数后卫奇数则交换，每次把偶数放到最后
	复杂度： O(1) space, O(n^2) time.
	
> 3.数组中出现次数超过一半的数字 ([剑指offer Q28](https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 排序，在找median的值。需要判断该值是否真的出现超过一半次数（出现超过一半必为排序中位数，但中位数未必超过一半）
	复杂度： O(1) space, O(nlogn) time.
	
	方法2: 使用最大/最小堆。构建堆，再推出找到中位数
	复杂度： O(n) space, O(n+klogn) time. 当n>>k时效率高
	
	方法3: QuickSelect通过找到第k小的数找到中位数
	复杂度： O(1) space, O(n) time（On average）. 
	
> 4.最小的K个数 ([剑指offer Q29](https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))
	
	方法1: 使用最小堆。构建堆，再推出直到第k个数
	复杂度： O(n) space, O(n+klogn) time. 当n>>k时效率高
	
	方法2: QuickSelect通过找到第k小的数找到中位数。同快排，通过partition找到中间pivot的位置
			如果pivot是第k个则返回。大于k则partition前面的数组，小于k则partition后面的数组
	复杂度： O(1) space, O(n) time（On average）. 
	
> 5.把数组排成最小的数 ([剑指offer Q32](https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))
	
	方法1: 定义一种排序方式。当“前+后”比“后+前”小时，前<后。排序后返回即可
			需要证明该排序定义的A1A2A3....An是最小的。可用反证法证明
	复杂度： O(1) space, O(nlogn) time.
	
> 6.数组中的逆序对 ([剑指offer Q35](https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))
	
	方法1: 暴力搜索 
	复杂度： O(1) space, O(n^2) time.
	
	方法2: MergeSort思想，每次合并两个数列，返回的count=前数列count+后数列count+merge产生的count。
			注意count可能会特别大，使用long long来保存
	复杂度： O(n) space, O(nlogn) time.
	
> 7.数字在排序数组中出现的次数 ([剑指offer Q37](https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))
	
	方法1: 暴力查找 
	复杂度： O(1) space, O(n) time.
	
	方法2: binaryCount. 
			如果mid>target,返回binaryCount(前段）
			如果mid<target,返回binaryCount(后段）
			如果mid>=target,返回binaryCount(前段）+binaryCount(后段）+1
	复杂度： O(n) space, O(logn) time.
	
> 8.和为S的两个数字 ([剑指offer Q42](https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))
	
	方法1: 排序后使用前后两个pointer查找
	复杂度： O(1) space, O(nlogn) time.
	
	方法2: 使用hash。保存遍历的数字，新数字判断差值是否在hash中
	复杂度： O(n) space, O(n) time.
	
> 9.和为S的连续正数序列 ([剑指offer Q41](https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))
	
	方法1: 前后双指针。根据和的情况分别移动两个指针。 
	复杂度： O(1) space, O(n) time.
	
> 10.扑克牌顺子 ([剑指offer Q45](https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))
	
	方法1: 先排序，计算大小王（0）的个数，当n_0<4时，剩余的最大值-最小值<=4.（注意判断数值是否在[0,13]）
	复杂度： O(1) space, O(1) time.
	
> 11.数组中重复的数字 ([剑指offer Q50](https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))
	
	方法1: 使用hash table储存，直到遇到第一个重复的数字
	复杂度： O(n) space, O(n) time.
	
	方法2: 将每个数字i移动到第i个位置。
	复杂度： O(1) space, O(n) time.

> 12.不用除法构建乘积数组 ([剑指offer Q51](https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))
	
	方法1: 暴力构建，两个for loop
	复杂度： O(n^2) space, O(1) time.
	
	方法2: 用两个数组分别表示从左/右开始到某位置i的累积乘积，dp方式求解
	复杂度： O(n) space, O(n) time.
	
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

> 1.递增二维数组中的查找 ([剑指offer Q1](https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1))

	方法1: 从右上角开始判断，小了往下， 大了往左。
	复杂度： O(1) space, O(n) time.
	
> 2.顺时针打印矩阵 ([剑指offer Q19](https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 每次开始都是(0,0)->(1,1)->(2,2)->...->(k,k)，直到2k>=n_row或2k>=n_col
			对每个(k,k)开始的circle，四个方向找到头尾断点打印（但要判断各方向上是否需要打印。）




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
```c++
char* str													 ## String by char pointer. Then end is always '\0'
```
凡是字符串，可以考虑用 "unsigned int table[256]={0}" 来储存每个char的信息。
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

> 1.替代空格: " " -> "%20" ([剑指offer Q2](https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 扫描一遍计算空格个数，提前分配string，在扫描一遍双指针替换
	复杂度： O(n) time.
	
	方法2: python使用split(" ") 与 "%20".join()函数
	复杂度: O(n) time.

> 2.字符串的排列 ([剑指offer Q27](https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 先递归返回str[1:]的全排列，再将该数字插入每个全排列的不同位置，推入队列/数组，并将原来的全排列弹出
			最后需要通过hashtable去除重复的排列
	复杂度： O(n) space, O(n^2) time.
	
> 3.第一个只出现一次的字符 ([剑指offer Q34](https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 使用hash table保存遍历结果，value为出现次数。再扫描一次字符串输出第一个value=1的字符
	复杂度： O(n) space, O(n) time.
	
	方法2: 因为字符个数有限，使用一个unsigned int table[256]保存每个char的出现个数。每个字符对应位置为int(str[i])。
	复杂度： O(1) space, O(n) time.
	
> 3.左旋转字符串 ([剑指offer Q43](https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 先反转[:n],再翻转[n:],最后整体翻转
	复杂度： O(1) space, O(n) time.
	相关问题：翻转单词顺序列
	
> 4.把字符串转换成整数 ([剑指offer Q49](https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 注意第一位为+/-，溢出，invalid char，“”的情况
	复杂度： O(1) space, O(n) time.
	
> 5.正则表达式匹配 ([剑指offer Q52](https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 递归判断。注意到字符串尾时=='\0'
			下一位不为'*'时，只有*str==*pattern或者*str!='\0'&&*pattern=='.'，将两个都向前一位递归判断
			下一位是‘*’时：
				同样的条件满足时，判断match(str+1,pattern)或match(str,pattern+2) --不match或者match一至多位
				不满足只判断match(str,pattern+2) -- 则没有match上该位
				
> 6.表示数值的字符串 ([剑指offer Q53](https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2?tpId=13&tqId=11206&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 分为e/E前后判断。后面的只能是整数。前面的最多只能有一个dot。注意边界检查条件。


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

> 1.从尾到头返回链表的值 ([剑指offer Q3](https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 反转链表再返回
	复杂度： O(1) space, O(n) time.
	
	方法2: 用额外的stack储存，再返回
	复杂度： O(n) space, O(n) time.
	
> 2.链表中倒数第k个结点 ([剑指offer Q14](https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 双指针，让头指针先走k步，再让前后指针一起走
	复杂度： O(1) space, O(n) time.
	
> 3.反转链表 ([剑指offer Q15](https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 常规操作
	复杂度： O(1) space, O(n) time.
	
> 4.合并两个排序链表 ([剑指offer Q16](https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 递归。若有一个指针为空，返回另一个指针，否则指向数值较小的指针，并移动该指针头，递归得到
	复杂度： O(1) space, O(n) time.
	
> 5.复杂链表的复制 ([剑指offer Q25](https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 先复制所有的next节点，并用map保存两个链表1on1的对应。然后复制random指针，通过map找到对应的值
	复杂度： O(n) space, O(n) time.
	
	方法2: 现在同一个链表中每个节点后面添加一个复制节点。在扫描一次将后面的复印节点random指针指向对应的复制节点
	复杂度： O(1) space, O(n) time.
	
> 6.两个链表的第一个公共结点 ([剑指offer Q36](https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 使用一个map保存链表1的结果。链表2扫描找到第一个在map中的数
	复杂度： O(n) space, O(n) time.
	
	方法2: 计算两个链表的长度，找到长度差d。长链表先走d步，两个再一起走知道相等
	复杂度： O(1) space, O(n) time.
	
> 7.圆圈中最后剩下的数(约瑟夫环问题) ([剑指offer Q46](https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6?tpId=13&tqId=11199&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 从数组构建链表，然后loop返回
	复杂度： O(n) space, O(mn) time.
	
	方法2: 归纳法。推出f(n,m) = (f(n-1,m)+m)%n。f(1,m)=0. 再dp求得
	复杂度： O(1) space, O(n) time.
	
> 8.链表中环的入口结点 ([剑指offer Q55](https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)) ([Leetcode Q142](https://leetcode.com/problems/linked-list-cycle-ii/))

	方法1: 主要为数学推导。双指针，快指针每次两步，慢指针每次一步。
			若有环，快慢指针会相遇。假设到环入口要a步，环长r步。慢指针走了k步与快指针相遇，慢指针在环上走了t步。
			则有a+t=k -> 2k = 2a+2t = a + nr + t， n为快指针额外走的圈数
			nr = a+t = k -> (n-1)r + r-t = a
			所以此时在安排一个指针从头与慢指针一起走，两个经过a步之后必定相遇在入口
	复杂度： O(1) space, O(n) time.
	相关问题：链表是否有环（=快慢指针是否相遇）
	
> 9.删除链表中重复的结点 ([剑指offer Q56](https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 递归判断是否遇到重复节点。是的话跳过这一段。注意下一节点为null的情况。
	复杂度： O(1) space, O(n) time.
	
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

> 1.从前序遍历与中序遍历结果重建二叉树 ([剑指offer Q4](https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 前序遍历数组[根结点，左子树节点，右子树节点] && 中序遍历数组[左子树节点，根结点，右子树节点]
		于是通过前序的第一个root，将中序分隔开来，递归重建左右子树
	
> 2.树的子结构 ([剑指offer Q17](https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 递归。如果root1==root2，递归判断左右子树是否完全相等；若不是，递归判断root1的左右子树是否是包含root2子树
	
> 3.二叉树的镜像 ([剑指offer Q18](https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 递归。互换左右子树，再递归完成子树的替换
	复杂度： O(1) space, O(n) time.
	
	方法2: 使用queue，每次互换最头上的节点的左右子树，再将左右子树的节点推入队列
	复杂度： O(n) space, O(n) time.
	
> 4.从上往下打印二叉树（层级遍历） ([剑指offer Q22](https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 使用queue，每次弹出队列的头，将左右子树推入队尾
	复杂度： O(n) space, O(n) time.
	相关问题：把二叉树打印成多行（每次要记录queue的大小，每次pop掉一层的节点）
	
> 5.二叉搜索树的后序遍历序列 ([剑指offer Q23](https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 后序遍历数组[左子树节点，右子树节点，根结点]
			每次通过根节点找到数组前面第一个比根节点大的数作为右子树开始（找不到则返回自己的位置）。
			判断断开的右子树是否全部比根节点大
			再递归判断左右子树是否为二叉搜索树
			
> 6.二叉树中和为某一值的路径([剑指offer Q24](https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 递归。每次查找左右子树值为target-root的路径，存在则将自己推入路径。只有叶节点能直接放回路径。
	
> 7.二叉搜索树与双向链表([剑指offer Q26](https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 递归。用一个自定义的TopEndNode保存左右子树恢复的双向链表的头尾。再与root节点融合成新的双向链表
    struct TopEndNode {
        struct TreeNode* top;
        struct TreeNode* end;
        TopEndNode(): top(NULL), end(NULL) {}
    };
    
> 8.二叉树的深度([剑指offer Q38](https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b?tpId=13&tqId=11191&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 递归。叶节点返回深度为1.根节点返回1+max(左深度，右深度）
	
> 9.平衡二叉树判断([剑指offer Q39](https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 递归求出左右子树的深度。如果深度相差不超过1则为平衡树。递归判断左右子树
	
	方法2: 方法1需要重复访问节点。于是从叶节点记录depth的深度并递归返回到根节点，相当于dp。
	       int depth = 0;
           return IsBalanced(pRoot, &depth);
           
> 10.树中两个节点的最低公共祖先(剑指offer书中)

	- 若为二叉搜索树，假设两个节点的值分别为min_v, max_v, 则可以从root找到第一个min_v < node < max_v的节点。若node等于其中某个值，则其中一个节点为另一节点的子孙
	- 若节点包含指向父节点的指针，则可将问题转化为找两个链表的第一个公共节点
	- 若都不满足（不一定为二叉树，不是搜索树，没有指向父节点的指针），则先从root找到到达两个节点的path（递归+深搜），然后比较两个path，求出两条路径的最后公共节点

> 11.二叉树的下一个结点([剑指offer Q57](https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 多种情况判断
			- node为空时，返回NULL
			- node右子树存在时，返回右子树最左下的叶节点
			- node不为root时，找到第一个 节点是-父节点的左节点的-父节点。
				即 if (pNode->next->left==pNode)
                	return pNode->next;
                	
> 12.对称的二叉树([剑指offer Q58](https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=11211&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 求出pRoot的镜像树pRoot_mirror,对比两个树是否完全一致
	复杂度： O(n) space, O(n) time, and need repeative visit.
	
	方法2: 对比root的两个子树是否对称，可递归判断(left->right,right->left) && (left->left,right->right) 是否都对称
	复杂度： O(1) space, O(n) time.
	
> 13.按之字形顺序打印二叉树([剑指offer Q59](https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 用两个stack记录每层结果，用一个bool记录是向左还是向右遍历。
		  每次将一个stack中的子节点向另一个方向传输。通过方向确定先传左还是先传右
	复杂度： O(n) space, O(n) time


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

> 1.两个栈实现队列 ([剑指offer Q5](https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 往stack1中push; pop时如果stack2为空，先将stack1从顶pop过来，然后返回stack2的top，不为空则直接返回
	
> 2.包含min函数的栈 ([剑指offer Q20](https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 用一个额外的栈保存至今最小的树，与value栈同步。若新加的数更小，推入新树，否则推入栈顶的树
	复杂度： O(n) space, O(1) time for min().
	
> 3.栈的压入、弹出序列 ([剑指offer Q21](https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 用一个额外的栈按照压入的顺序不断推入，但当该栈顶的数等于弹出序列的头，弹出栈顶数与弹出序列的头（或移动index）
	复杂度： O(n) space, O(n) time.


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

> 1.最小的K个数([剑指offer Q29](https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))
	
	方法1: 使用最小堆。构建堆，再推出直到第k个数
	复杂度： O(n) space, O(n+klogn) time. 当n>>k时效率高
	
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

> 1.和为S的两个数字 ([剑指offer Q42](https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))
	
	方法1: 排序后使用前后两个pointer查找
	复杂度： O(1) space, O(nlogn) time.
	
	方法2: 使用hash。保存遍历的数字，新数字判断差值是否在hash中
	复杂度： O(n) space, O(n) time.
	
> 2.数组中重复的数字 ([剑指offer Q50](https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))
	
	方法1: 使用hash table储存，直到遇到第一个重复的数字
	复杂度： O(n) space, O(n) time.
	
	方法2: 将每个数字i移动到第i个位置。
	复杂度： O(1) space, O(n) time.
	
> 3.第一个只出现一次的字符 ([剑指offer Q34](https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 使用hash table保存遍历结果，value为出现次数。再扫描一次字符串输出第一个value=1的字符
	复杂度： O(n) space, O(n) time.
	
	方法2: 因为字符个数有限，使用一个unsigned int table[256]保存每个char的出现个数。每个字符对应位置为int(str[i])。
	复杂度： O(1) space, O(n) time.
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

> 1.二进制中的1的个数 ([剑指offer Q11](https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: for loop 查看每一位的是否为1
	复杂度： O(1) space, O(1) time.
	
> 2.数组中只出现一次的两个数字 ([剑指offer Q40](https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 使用map记录每个数字出现的个数
	复杂度： O(n) space, O(n) time.
	
	方法1: 使用xor（a xor a = 0）. 将所有数字xor一遍。找到结果中不为0的一位，则两个数字在这一位必不同
			按照该位将数字分为两组。分别进行xor并输出两个结果
	复杂度： O(1) space, O(n) time.
	
>3.不用加减乘除做加法([剑指offer Q48](https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 位运算。xor为sum， and 与 <<1为carry。直到carry不为0

---
<br />


# <h2 id="12">动态规划（Dynamic Programming）</h2>
### 问题及思路

> 1.斐波拉契数列 ([剑指offer Q7](https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: for loop 动态计算后面的值，注意溢出，long long保存结果
	复杂度： O(1) space, O(n) time.
	相关： 青蛙跳， 矩形覆盖
	
> 2.连续子数组的最大和 ([剑指offer Q30](https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1:，使用一个额外的sum保存到该数的最大sum。如果sum为负则定义改出的sum为自身（最大sum必然不包括前面的负数和）
	复杂度： O(1) space, O(n) time.


---
<br />

# <h2 id="13">数值计算（Numerical Calculation)</h2>
### 知识
| 类型 | 位 | 范围 |
| :-----| ----: | :----: |
| char | 8 bit | -128 到 127 或者 0 到 255 |
| unsigned char | 8 bit | 0 到 255 |
| signed char | 8 bit | -128 到 127 |
| int | 32 bit | -2147483648 到 2147483647 |
| unsigned int |	32 bit | 0 到 4294967295
| signed int | 32 bit  | -2147483648 到 2147483647
| short int | 16 bit  | -32768 到 32767
| unsigned short int | 16 bit | 0 到 65,535
| signed short int | 16 bit | -32768 到 32767
| long int | 64 bit | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807
| signed long int | 64 bit | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807
| unsigned long int | 64 bit | 0 to 18,446,744,073,709,551,615
| float | 32 bit | +/- 3.4e 到 +/- 38 (~7 个数字)
| double | 64 bit | +/- 1.7e 到 +/- 308 (~15 个数字)
| long double | 128 bit | +/- 1.7e 到 +/- 308 (~15 个数字)
### C++用法
```c++
abs(float) <= 1e-6                                          ## whether float value is 0
abs(double) <= 1e-15                                        ## whether double value is 0
max_element(vec.begin(), vec.end())                         ## return the max
min_element(vec.begin(), vec.end())                         ## return the min
INT_MAX / INT_MIN                                           ## max and min of integer
```
### Python用法
```python
float('Inf')             ## infinite large. -float('Inf') is smallest
sum(list)				 ## sum of all elements in list
```

### 问题及思路

> 1.数值的整数次方([剑指offer Q12](https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00?tpId=13&tqId=11165&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 主要考察是否覆盖全部case(0^0, 0^neg, 0^pos, n^0, n^neg, n^pos).
		  注意的是，对于c++，判断浮点数是否为0应留有error
		  对于exp的计算，可以用二分法
	复杂度： O(1) space, O(logn) time.
	
> 2.从1到n整数中1出现的次数([剑指offer Q31](https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 归纳法。对每一个数位上分别求出该数位上1出现的个数。
	复杂度： O(1) space, O(logn) time.
	
	int count = 0;
    int a, b = 0;
    for(int m=1; m<=n; m*=10){
        a = n/m;
        b = n%m;
        count += (a+8)/10*m + (a%10==1)*(b+1);
        // count is for the 1 at each position.
        // (a+8)/10*m is by counting the before number from 0.
        // (a%10==1)*(b+1) is for counting the smaller fraction
    }
    return count;
    
> 3.丑数([剑指offer Q33](https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 用三个队列分别表示x2,x3,x5的结果。每次讲三个队列最小的头推出加入输出数组（重复则一起推出）。
			将该数x2,x3,x5之后分别推入三个队列的尾部
			实现的时候可以只采用一个输出数组，并用3个指针指向该输出数组的位置，减少extra space。
	复杂度： O(1) space, O(n) time.
	
>4.不使用加减乘除和判断语句求1～n的和([剑指offer Q47](https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 采用递归. n==0时 n && 不再计算直接返回
	复杂度： O(1) space, O(logn) time.
	 int res = n;
     n && (res += Sum_Solution(n-1));
     return res;
     
>5.不用加减乘除做加法([剑指offer Q48](https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 位运算。xor为sum， and 与 <<1为carry。直到carry不为0

     
---
<br />

# <h2 id="14">贪心算法（Greedy Algorithm）</h2>
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

# <h2 id="15">排序算法（Sorting）</h2>
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

# <h2 id="16">大数据问题（Big Data）</h2>
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

# <h2 id="17">其他（Other）</h2>
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






