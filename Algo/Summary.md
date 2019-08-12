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
int *ptr = new int[n]			      ## init array with size n
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
	相关问题：旋转数组的查找(CC150 053)：按照mid与target的值比较
			A[mid]<target时，只有mid在右侧且x在左侧才向左查找，否则都向右
			A[mid]>target时，只有mid在左侧且x在右侧才向右查找，否则都向左

> 2.调整数组顺序使奇数位于偶数前面 ([剑指offer Q13](https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 直接扫描，分别保存奇数与偶数数组，再合并
	复杂度： O(n) space, O(n) time.

	方法2: 冒泡排序的方法，每次前为偶数后卫奇数则交换，每次把偶数放到最后
	复杂度： O(1) space, O(n^2) time.

	方法3: 双指针，从头和尾分别遍历。当前为偶数后为奇数时交换。否则向中间移动指针
	复杂度： O(1) space, O(n) time.

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
	相似问题: 魔术引索([CC150 Q42]-当A[i]>i时，i直接跳到A[i]，避免无用搜索

> 12.不用除法构建乘积数组 ([剑指offer Q51](https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 暴力构建，两个for loop
	复杂度： O(n^2) space, O(1) time.

	方法2: 用两个数组分别表示从左/右开始到某位置i的累积乘积，dp方式求解
	复杂度： O(n) space, O(n) time.

> 13.荷兰旗问题（三色分离） ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/02.07.html))

	方法1: Sorting counting
	复杂度： O(1) space, O(n) time.

	方法1: 使用三个指针l1,l2,l3。l1&l2指向头，l3指向尾
			当l2==0时，交换l1，l2的值，l1,l2各加1
			当l2==1时，l2加1
			当l2==2时，交换l3，l2的值，l3减1
			直到l2==l3
	复杂度： O(1) space, O(n) time.
	
> 14.最小调整有序([CC150 Q65](https://www.nowcoder.com/practice/091c2f1cf441484f81696f08328b06cd?tpId=8&tqId=11059&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 用两个vector分别表示从左到右的最大值/从右到左的最小值。
		从左到右遍历最小值，当最小值第一次不为自身，即右边有更小的数，一定要调整
		从右到左遍历最大值，当最大值第一次不为自身，即左边有更小的数，一定要调整
	复杂度： O(n) space, O(n) time.
	
	方法2: 不需要用vector保存所有的结果。只要记录从左到右最后一次最大值更改，和从右到左最后一次最小值更改即可。
	复杂度： O(1) space, O(n) time.
	
> 15.下一个最大数([CC150 Q73](https://www.nowcoder.com/practice/11ae41035eef4ed9b354d0752f5abc6f?tpId=8&tqId=11067&tPage=4&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 用一个stack保存从后往前的值，当检查A[i]后的第一个最大，将stack pop至找到top>A[i]，再将A[i]推进去。
		原理在于，后面比A[i]小的数都不用继续保存了，因为A[i]相对于他们总是下一个最大的数
	复杂度： O(n) space, O(n) time.
	
> 16.下一个最大数II([CC150 Q74](https://www.nowcoder.com/practice/a0c19f3489774fe693d71490ce83b648?tpId=8&tqId=11068&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 用一个set当作二叉搜索树，每次从后insert并找到upper_bound.找不到返回-1
	复杂度： O(n) space, O(logn) time插入和查找.
	
> 17.单词最近距离([CC150 Q74](https://www.nowcoder.com/practice/1a002eed40054042867eb1aa5b98fb11?tpId=8&tqId=11069&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2013/03/02/20.5/))

	方法1: 每次遇到其中一个string就更新其pos，计算dis并更新最小距离
	复杂度： O(1) space, O(n) time
	
	方法2: 如果想要对任意查找都快，可以将所有的pair调整顺序后保存进map
	复杂度： O(n^2) space, O(n^2) time 预处理，O(1) time查找



---
<br />

# <h2 id="2">矩阵(Matrix)</h2>
### C++用法
```c++
int arr[4][5] = {}						## init an empty matrix
arr[row][col]                           ## acces the idx
int** mat = new int*[n];            	## Init an empty matrix by pointer.
	for(int i=0;i<n;i++)
		mat[i] = new int[m];
```
```c++
vector<vector<int> > v;                  ## init empty matrix
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

> 3.旋转矩阵 ([CC150 Q6](https://www.nowcoder.com/practice/17ab1e527c504df09a600e1af09d9a60?tpId=8&tqId=10999&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2012/12/08/1.6/))

	方法1: 两个for loop直接copy
	复杂度： O(n^2) space, O(n^2) time.

	方法2: inplace交换，两次翻转。先对角线交换，再垂直方向交换
	复杂度： O(1) space, O(n^2) time.
	
> 4.清除行列 ([CC150 Q7](https://www.nowcoder.com/practice/c95aac1506574dfc8ad44c3939c6739d?tpId=8&tqId=11000&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2012/12/09/1.7/))

	方法1: 用两个一维数组分别表示这一行/列是否出现过0.再扫描一遍只要判断该点的行列是否出现过0即可
	复杂度： O(n) space, O(n^2) time.

---
<br />

# <h2 id="3">字符串(String)</h2>
### C++用法
```c++
string s（“sss")                                             ## init string
string s（len, " ")	                                         ## init empty string by length
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
stof(str)                                                    ## string to float
sort(&str[0], &str[0]+str.length())	                         ## Sort a string
```
```c++
char* str													 ## String by char pointer. Then end is always '\0'
```
```c++
istringstream is(str)                                        ## init istringstream by string
	string s;                                                ## read in each string segment, seperate by " "
	while (is >> s) {}
ostringstream os;                                            ## init ostringstream
	os.str("")                                               ## clear stream
	while () {os << "str "}                                  ## assign values to ostringstream
	return os.str()                                          ## change the ostringstream to string
```
凡是字符串，可以考虑用 "unsigned int table[256]={0}" 来储存每个char的信息。

使用int arr[8]可以更少的使用空间。每一个char可有 arr[pos/32]<<(pos%32) 表示。
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

> 2.字符串的排列 ([剑指offer Q27](https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?tpId=13&tqId=11180&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))([CC150 Q44](https://www.nowcoder.com/practice/8380c8cf28954a188362206b1991b5d6?tpId=8&tqId=11038&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 先递归返回str[1:]的全排列，再将该数字插入每个全排列的不同位置，推入队列/数组，并将原来的全排列弹出
			最后需要通过hashtable去除重复的排列
	
	方法2: 递归。每一次将i>cur移到cur的位置做一次permutation。再swap回去
	
	方法3: 递归。每一次取其中的一位，将剩下的字符串premute之后，将该位放在开头

> 3.第一个只出现一次的字符 ([剑指offer Q34](https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 使用hash table保存遍历结果，value为出现次数。再扫描一次字符串输出第一个value=1的字符
	复杂度： O(n) space, O(n) time.

	方法2: 因为字符个数有限，使用一个unsigned int table[256]保存每个char的出现个数。每个字符对应位置为int(str[i])。
	复杂度： O(1) space, O(n) time.

> 3.左旋转字符串 ([剑指offer Q43](https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 先反转[:n],再翻转[n:],最后整体翻转
	复杂度： O(1) space, O(n) time.
	相关问题：翻转单词顺序列。旋转链表（同样分别旋转两部分最后一起翻转）

> 4.把字符串转换成整数 ([剑指offer Q49](https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 注意第一位为+/-，溢出，invalid char，“”的情况。
		   判断溢出即可以用long long表示值与MAX_INT对比，也可以再乘10前对比n与MAX_INT/10.
	复杂度： O(1) space, O(n) time.

> 5.正则表达式匹配 ([剑指offer Q52](https://www.nowcoder.com/practice/45327ae22b7b413ea21df13ee7d6429c?tpId=13&tqId=11205&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 递归判断。注意到字符串尾时=='\0'
			下一位不为'*'时，只有*str==*pattern或者*str!='\0'&&*pattern=='.'，将两个都向前一位递归判断match(str+1,pattern+1)
			下一位是‘*’时：
				同样的条件满足时，判断match(str+1,pattern)或match(str,pattern+2) --不match或者match一至多位
				不满足只判断match(str,pattern+2) -- 则没有match上该位

> 6.表示数值的字符串 ([剑指offer Q53](https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2?tpId=13&tqId=11206&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 分为e/E前后判断。后面的只能是整数。前面的最多只能有一个dot。注意边界检查条件。

> 7.字符串包含 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/01.02.html))

	方法1: 暴力查找
	复杂度： O(1) space, O(mn) time.

	方法2: 先排序，后双指针查找
	复杂度： O(1) space, O(mlogm+nlogn) time.

	方法3: 使用hashtable。字符串有限所以额外空间为O(1)。因为数量=26，使用一个int更好。
	复杂度： O(1) space, O(m+n) time.

> 8.回文判断 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/01.04.html))

	方法1: 使用stack，全部推入栈中。如果再次推出相等则为回文
	复杂度： O(n) space, O(n) time.

	方法2: 双指针从两端/中间双向查询
	复杂度： O(1) space, O(n) time.
	相关问题：链表是否回文（使用栈/快慢指针，快指针到达终点后翻转链表）

> 9.最长回文子串 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/01.05.html)) ([Leetcode Q5](https://leetcode.com/problems/longest-palindromic-substring/))

	方法1: 从每个位置开始，向两侧进行扩展并判断。需要饱含奇偶两种长度情况
	复杂度： O(1) space, O(n^2) time.

	方法2: Manacher算法 （to be understand, not implement yet）
	复杂度： O(1) space, O(n) time.
	
> 10.两个字符串是否同构 ([CC150 Q3](https://www.nowcoder.com/practice/164929d4acd04de5b0ee2d93047b3b20?tpId=8&tqId=10996&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2012/12/06/1.4/))

	方法1: 对两个字符串先排序，在比较是否完全一样
	复杂度： O(1) space, O(nlogn) time.

	方法2: 用额外数组记录出现a中字符出现次数，再依次通过b的减去判断是否为0
	复杂度： O(n) space, O(n) time.
	
> 11.是否为旋转字符串 ([CC150 Q8](https://www.nowcoder.com/practice/bc12808a2b0f445c96a64406d5513e96?tpId=8&tqId=11001&rp=1&ru=%2Fta%2Fcracking-the-coding-interview&qru=%2Fta%2Fcracking-the-coding-interview%2Fquestion-ranking&tPage=1))([CC150 Sol](http://hawstein.com/2012/12/10/1.8/))

	方法1: 对s1每一个break point，检查后+前的组合是否为s2
	复杂度： O(1) space, O(n^2) time.

	方法2: 构造一个O(n)时间的子串检查函数，如果s2是s1+s1的子串，则s2为s1的旋转
	复杂度： O(n) space, O(n) time.
	相关问题：子串判断
	
> 12.最长合成字符串 ([CC150 Q76](https://www.nowcoder.com/practice/92a6faa7377f4c049a18154b24458d2a?tpId=8&tqId=11070&tPage=4&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2013/03/04/20.7/))

	方法1: 先将字符串组按照长度排序。从长的开始，判断该字符串是否可以被后面的字符串构成。
		  每次可将后面的字符串保存在map中确定是否出现。对该判断字符串，如果map出现return true，
		  否则依次递归判断构成该字符串的前后两个子串是否可以被构成
		  
> 13.子串查找

	方法1: to be done
	
> 13_1.字符串多模式匹配 ([CC150 Q77](https://www.nowcoder.com/practice/917a800d4de1423394827932f4725c68?tpId=8&tqId=11071&tPage=4&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2013/03/05/20.8/))

	方法1: 对vector中每个子串，用s.find()判断其是否为一个子串
	
	方法2: 构造一个Trie树。将str所有的后缀插入树中。如果为子串，则必定在树中




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

	方法1: 常规操作,与1相同
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

	方法2: 归纳法。推出f(n,m) = (f(n-1,m)+m)%n。f(1,m)=0. 再dp求得。如果起点为1则+1
	复杂度： O(1) space, O(n) time.

> 8.链表中环的入口结点 ([剑指offer Q55](https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)) ([Leetcode Q142](https://leetcode.com/problems/linked-list-cycle-ii/)) ([CC150 Sol](http://hawstein.com/2012/12/17/2.5/))

	方法1: 主要为数学推导。双指针，快指针每次两步，慢指针每次一步。
			若有环，快慢指针会相遇。假设到环入口要a步，环长r步。慢指针走了k步与快指针相遇，慢指针在环上走了t步。
			则有a+t=k -> 2k = 2a+2t = a + nr + t， n为快指针额外走的圈数
			nr = a+t = k -> (n-1)r + r-t = a
			所以此时在安排一个指针从头与慢指针一起走，两个经过a步之后必定相遇在入口
	复杂度： O(1) space, O(n) time.
	相关问题：链表是否有环（=快慢指针是否相遇）
	
	方法2: 用一个map保存是否遇到过相同指针。指针不停向前，若遇到相同map中存在证明有环且为环的入口 
	复杂度： O(n) space, O(n) time.

> 9_1.删除排序链表中重复的结点 ([剑指offer Q56](https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 递归判断是否遇到重复节点。是的话跳过这一段。注意下一节点为null的情况。
	复杂度： O(1) space, O(n) time.

> 9_2.删除未排序链表中重复的结点 ([CC150 Sol](http://hawstein.com/2012/12/13/2.1/))

	方法1: 双指针，每次遇到一个，删除后面所有相同的。
	复杂度： O(1) space, O(n^2) time.

	方法2: 用一个hash判断该节点是否曾经出现过
	复杂度： O(n) space, O(n) time.

> 10.删除链表节点 ([CC150 Q9](https://www.nowcoder.com/practice/6a668a3960e24d3ea04bba89109c6451?tpId=8&tqId=11003&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2012/12/15/2.3/))


	方法1: 将指向节点的下一个节点的值copy至指向节点。再删除下一个节点
			如果该节点是尾节点，则必须要遍历
	复杂度： O(1) space, O(1) time. O(n) for ending node
	
> 10.分割链表 ([CC150 Q10](https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&tqId=11004&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))


	方法1: 使用大小两个链表进行添加。注意大链表最后next要指向null.
	复杂度： O(1) space, O(n) time.
	
> 11.链表相加 ([CC150 Q11](https://www.nowcoder.com/practice/ed85a09f0df047119e94fb3e5569855a?tpId=8&tqId=11005&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2012/12/16/2.4/))([LeetCode Q2](https://leetcode.com/problems/add-two-numbers/))


	方法1: 注意对while条件的判断，只要(a || b || carry)即可继续，赋值可用a?a->val:0进行。减少过多代码
	复杂度： O(1) space, O(n) time.
	
> 12.回文链表 ([CC150 Q12](https://www.nowcoder.com/practice/baefd05def524a92bcfa6e1f113ed4f0?tpId=8&tqId=11006&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))


	方法1: 使用一个stack，全部推入判断堆顶是否一次相等
	复杂度： O(n) space, O(n) time.
	
	方法2: 使用一个stack和快慢指针，将慢指针经历的推入堆中，在慢指针一次遍历比较stack顶。注意长度为奇偶时的区别
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
```c++
/**
 * Definition for Trie tree
 * struct TrieNode {
 *     char c;
 *     struct TrieNode* ptr[26];
 *     TrieNode(char c): c(c) {
 *         memset(ptr, 0, sizeof(ptr));
 *     }
 * };
 */
```

```c++
- set (Actually a RedBlack Tree in C++)
set<int> s                                                  ## init set
s.clear()                                                   ## clear the set
s.count(val)                                                ## count num of occur
s.empty()                                                   ## whether is umpty
s.insert(val)                                               ## insert val
s.erase(val)                                                ## erase val
s.find(val)                                                 ## find val and return iter
s.lower_bound(val)                                          ## return iter that is the first not less than val
s.upper_bound(val)                                          ## return iter that is the first larger than val
it = s.equal_range(val)                                     ## return iter that first&second are lower_bound and upper_bound
    *it->first
    *it->second
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
	相关问题：- 把二叉树打印成多行（每次要记录queue的大小，每次pop掉一层的节点）
			- 将某一层输出成为链表 (CC150 Q20)


> 5.二叉搜索树的后序遍历序列构造二叉树 ([剑指offer Q23](https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

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
	
	方法2: 将深度传入函数，避免多次重复调用

> 9.平衡二叉树判断([剑指offer Q39](https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))([CC150 Q17](https://www.nowcoder.com/practice/b6bbed48cd864cf09a34a6ca14a3976f?tpId=8&tqId=11011&rp=1&ru=%2Fta%2Fcracking-the-coding-interview&qru=%2Fta%2Fcracking-the-coding-interview%2Fquestion-ranking&tPage=1))([CC150 Sol](http://hawstein.com/2012/12/24/4.1/))

	方法1: 递归求出左右子树的深度。如果深度相差不超过1则为平衡树。递归判断左右子树

	方法2: 方法1需要重复访问节点。于是从叶节点记录depth的深度并递归返回到根节点，相当于dp。
	       int depth = 0;
           return IsBalanced(pRoot, &depth);

> 10.树中两个节点的最低公共祖先(剑指offer书中)

	- 若为二叉搜索树，假设两个节点的值分别为min_v, max_v, 则可以从root找到第一个min_v < node < max_v的节点。若node等于其中某个值，则其中一个节点为另一节点的子孙
	- 若节点包含指向父节点的指针，则可将问题转化为找两个链表的第一个公共节点
	- 若都不满足（不一定为二叉树，不是搜索树，没有指向父节点的指针），则先从root找到到达两个节点的path（递归+深搜），然后比较两个path，求出两条路径的最后公共节点

> 10_1.满二叉树的最低公共祖先([CC150 Q23](https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&tqId=11017&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 注意到每个节点的父亲编号都是自己的一半。用两个stack保存路径，查看最后相同的堆顶值
	复杂度： O(n) space, O(n) time.
	
	方法2: 直接比较两个编号。若不相等，大的数除以2，直到相等。
	复杂度： O(1) space, O(n) time.

> 11.二叉树的下一个结点([剑指offer Q57](https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 多种情况判断
			- node为空时，返回NULL
			- node右子树存在时，返回右子树最左下的叶节点
			- node不为root时，找到第一个 节点是-父节点的左节点的-父节点。
				即 if (pNode->next->left==pNode)
                	return pNode->next;
   
    方法2: 直接中序遍历
                	
> 11_1.二叉树的下一个结点(不存在父节点)([CC150 Q22](https://www.nowcoder.com/practice/60231d6931d543d4aadcb67851b21e4a?tpId=8&tqId=11016&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2012/12/28/4.5/))

	方法1: 用一个vector保存中序遍历的结果，找到对应值的下一个节点
	复杂度： O(n) space, O(n) time.
	
	方法2: 用一个stack记录中序遍历的结果。找到值时设一个flag=true，下一个遇到flag==true则输出
	复杂度： O(n) space, O(n) time.
	
	方法3: 直接用一个flag传入函数递归来做。（假设所有值>=0）
			如果root为null，返回-1.
			对左节点调用函数。如果返回不为-1，证明在左子树找到，返回该值。
			如果sign被设成了true，证明在左子树找到p，下一个恰好为root的值
			如果root->val==p，将sign设为true，
			返回右节点的递归结果（因为sign已经是true了，会直接输出下一个访问的节点的值）
	复杂度： O(1) space, O(n) time.

	
> 12.对称的二叉树([剑指offer Q58](https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=11211&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 求出pRoot的镜像树pRoot_mirror,对比两个树是否完全一致
	复杂度： O(n) space, O(n) time, and need repeative visit.

	方法2: 对比root的两个子树是否对称，可递归判断(left->right,right->left) && (left->left,right->right) 是否都对称
	复杂度： O(1) space, O(n) time.

> 13.按之字形顺序打印二叉树([剑指offer Q59](https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 用两个stack记录每层结果，用一个bool记录是向左还是向右遍历。
		  每次将一个stack中的子节点向另一个方向传输。通过方向确定先传左还是先传右
	复杂度： O(n) space, O(n) time

> 14.序列化二叉树([Leetcode Q297](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/))

	方法1: 用queue进行层级遍历，用#表示null，用空格隔开不同节点。使用istringstream与ostringstream便于序列化。
	复杂度： O(1) space, O(n) time

> 15.二叉树的中序遍历([Leetcode Q94](https://leetcode.com/problems/binary-tree-inorder-traversal/))

	方法1: 递归。传入一个可修改的vector，左子树先调用，root推入值，右子树在调用。
	复杂度： O(1) space, O(n) time

	方法2: 使用stack。p不为空时，推入自己，p指向p->left。p为空时，p=stack.top()，将p的值推入结果vector，stack pop()，再让p指向p->right
	复杂度： O(n) space, O(n) time

> 16.二叉树搜索树的第k个节点([Leetcode Q230](https://leetcode.com/problems/kth-smallest-element-in-a-bst/))

	方法1: 递归。先用一个函数递归求树的节点数目。如果左节点数目等于k-1，返回root；大于k-1则返回左子树的第k个；否则返回右子树的k-leftcount-1个节点
	复杂度： O(1) space, O(n) time，但是多次递归开销很大

	方法2: 先用15的方法1求出vector，在返回vector的第k-1个数
	复杂度： O(n) space, O(n) time，但是多次递归开销很大

	方法3: 使用15的方法2的stack，在推入的时候改为记录count，返回第k个count的时候的值
	复杂度： O(n) space, O(n) time

> 17.递增数列构建最低二叉搜索树([CC150 Q19](https://www.nowcoder.com/practice/01a12f94988649e39b554d95c45bfa6f?tpId=8&tqId=11013&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2012/12/26/4.3/))

	方法1: 每次取mid，递归构建
	
> 18.判断二叉搜索树([CC150 Q21](https://www.nowcoder.com/practice/536c0199151245f897da2c5390930657?tpId=8&tqId=11015&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 使用15中stack版的中序遍历，每次访问到一个点的时候记录下值，保证下一个访问的点比他大，不断更新该值
	复杂度： O(n) space, O(n) time
	
> 19.二叉树的最长路径([Leetcode Q543](https://leetcode.com/problems/diameter-of-binary-tree))

	方法1: 根节点最长路径=max(左节点最长路径，右节点最长路径，左深度+右深度）。深度可以传入函数递归
	复杂度： O(1) space, O(n) time
	
> 20.维护数组的rank([CC150 Q58](https://www.nowcoder.com/practice/0ade0d95c85349beb934a90b1d9b02be?tpId=8&tqId=11052&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 暴力检查
	复杂度： O(1) space, O(n^2) time
	
	方法2: 用二叉搜索树保存stream的结果，每次查找rank。
	复杂度： O(n) space, O(logn) time


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

	方法1: 用一个额外的栈保存至今最小的树，与value栈同步。若新加的数更小，推入新树，否则推入栈顶的树(事实上额外的栈不需要保存重复的最小值，如果新的值不小于栈顶的值则推入；如果pop的值==栈顶值一同pop掉)
	复杂度： O(n) space, O(1) time for min().

> 3.栈的压入、弹出序列 ([剑指offer Q21](https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 用一个额外的栈按照压入的顺序不断推入，但当该栈顶的数等于弹出序列的头，弹出栈顶数与弹出序列的头（或移动index）
	复杂度： O(n) space, O(n) time.
	
> 4.双栈排序 ([CC150 Q15](https://www.nowcoder.com/practice/d0d0cddc1489476da6b782a6301e7dec?tpId=8&tqId=11009&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2012/12/23/3.6/))

	方法1: Insertion sort的方法，每次把栈顶插到temp栈对应的地方，temp栈顶大的数先push回原来的栈即可
	复杂度： O(n) space, O(n^2) time.
	
> 5.合法括号 ([CC150 Q45](https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&tqId=11039&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2013/01/12/8.5/))

	方法1: 使用一个stack，当栈顶为'('且A字符为')'弹出栈顶，否则一次输入A的字符。如果合法，stack应为空。
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
```c++
deque<int> dq                                               ## init deque, which is like queue but can add/rm bidirectional
dq.size()                                                   ## size of deque
dq.empty()                                                  ## whether is empty
dq.front()                                                  ## first elem
dq.back()                                                   ## last elem
dq.at(idx)                                                  ## access at idx
dq.push_back(v)                                             ## push to last
dq.push_front(v)                                            ## push to first
dq.pop_back()                                               ## remove the last
dq.pop_front()                                              ## remove the first
dq.insert(iter, v)                                          ## insert at iter
dq.erase(iter)                                              ## remove by iter
dq.clear()                                                  ## clear
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

> 1.滑动窗口的最大值([剑指offer Q64](https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=4))

	方法1: 暴力搜索每个slidingwindow。可以用dp思想稍微减少一点对比
	复杂度： O(1) space, O(nk) time.

	方法2: 使用一个动态维护的deque来构建每个窗口的slidingwindow。保证deque的头部永远是该windows内的最大值
		  每次加入的新的数之前，需要从尾部删除比新加的小的数。
		  然后从头删除已经不在slidingwindow内的数（所以deque存index而不存数字）
		  最后输出头部的数当作该窗口结果
	复杂度： O(k) space, O(n) time.

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

> 1.最小的K个数 ([剑指offer Q29](https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 使用最小堆。构建堆，再推出直到第k个数
	复杂度： O(n) space, O(n+klogn) time. 当n>>k时效率高

> 2.数据流中的中位数 ([剑指offer Q63](https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 内置vector，每次insert都保证sorted(插入排序)。
	复杂度： O(n) space, O(n) time for insertion. O(1) for getMedian

	方法2: 采用min heap + max heap. 保证min heap的数都比max heap大。且max heap的数总比min heap多。记录目前的count
			若现在count为偶数，插入是先进min heap，得到的min heap最小值释放并推入max heap。
			若现在count为奇数，插入是先进max heap，得到的max heap最大值释放并推入min heap。
			奇数的median返回max heap的最大，偶数的median返回min heap和max heap顶的平均值
	复杂度： O(n) space, O(logn) time for insertion. O(1) for getMedian

---
<br />


# <h2 id="9">哈希表（HashTable）</h2>
### C++用法
### 注意：c++中，map用红黑树实现，需要O(logn)时间查找/插入。unordered_map是真正的hash table
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
```c++
pair<int, double> p                                         ## pair init
pair<int, double> p(1, 1.1)                                 ## pair init and assign
p = make_pair(1, 1.1)                                       ## assign using make pair
p.first                                                     ## first value
p.second                                                    ## second value
map<pair<int, int>, bool>                                   ## map with pair
map[make_pair(1,1)]                                         ## access by pair key
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
	
> 4.变位词排序 ([CC150 Q52](https://www.nowcoder.com/practice/764edc8f2a6147429a098f422753853b?tpId=8&tqId=11046&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 所有的变位词按照字典序排序后都相同，可视为hash key。使用hash table保存看是否存在即可
	复杂度： O(n) space, O(nlogn) time.

---
<br />


# <h2 id="10">图（Graph）</h2>
### 知识
- 深度优先搜索(DFS): 递归 或 用stack
- 广度优先搜索(BFS): 递归 或 用queue
- 最短路径算法 (Shortest Path Algorithm): Dijkstra 算法, Floyd 算法
- 最小生成树 (Minimum Spanning Trees MST): Prim 算法, Kruskal 算法
- 网络流 (Network Flow)

### C++用法
```c++
int graph[][]					# Use Adjacency matrix. You can also design Node and use Adjacency List.
```
### Python用法
```python
list = [[]]					# Use Adjacency matrix
```

### 问题及思路

> 1.矩阵中的路径 ([剑指offer Q65](https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&tqId=11218&rp=2&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=4))

	方法1: 深搜，注意visit的表需要修改。注意传入函数的方式(dfs(int *&visit...))
	复杂度： O(n) space, O(n) time.

> 2.机器人的运动范围 ([剑指offer Q66](https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&tqId=11219&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 深搜. 判断时多加了条件而已。
	复杂度： O(n) space, O(n) time.
	
> 3.检查路径 ([CC150 Q18](https://www.nowcoder.com/practice/1b83885969f14329bf9222c1c54469a7?tpId=8&tqId=11012&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2012/12/25/4.2/))

	方法1: 深搜. 退出时可不将visit改为0，因为为有向图，不能到达则无需再次访问
	复杂度： O(n) space, O(n) time.
	
	方法2: 广搜. 用queue来实现 
	复杂度： O(n) space, O(n) time.
	
> 4.N皇后问题([CC150 Q48](https://www.nowcoder.com/practice/8b5d63163fbe48719f2dfe01fe9f7e54?tpId=8&tqId=11042&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2013/01/15/8.8/))

	方法1: 回溯/dfs，用rows[i]表示每一行的assignment，每次assign一行里边所有可能性，如果valid就去assign下一行。
			当八行都assign成功后，将传入的count++
			
> 5.迷宫([CC150 Q46](https://www.nowcoder.com/practice/365493766c514d0da0cd774d3d40fd49?tpId=8&tqId=11040&rp=3&ru=%2Fta%2Fcracking-the-coding-interview&qru=%2Fta%2Fcracking-the-coding-interview%2Fquestion-ranking&tPage=3))

	方法1: bfs. 将输入的map直接当作visit table。queue每次push一个pos(x*m+y)，向四个方向进行查找。map直接保存到达该格的步数 

> 6.字符串变换最短路径 ([CC150 Q79](https://www.nowcoder.com/practice/4818ae796bbc4a85a8cdd8e155c06d46?tpId=8&tqId=11073&tPage=4&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)）

	方法1: 使用bfs。相邻的定义即为两个字符串相差为1。用visit表示访问的距离。
		   queue保存遍历的字符串，用一个map将字符串和idx对应起来。主要注意开始时的字符串没有idx。
	
# <h2 id="11">位运算（Bit Manipulation）</h2>
### C++用法
```c++
	>>			 ## Shfit right(add the leftmost bit of original)
	<<			 ## Shift left(positive add 0, negative needs more steps). Exceed will change to Long(64 bits)
	|            ## OR
	&			 ## And
	^			 ## Exclusive OR
	~			 ## NOT
	0xffffffff   ## 32bit int in hex
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
	相关问题：只出现一次的三个数字（同样用某一位分组，产生一个奇数分组和一个偶数分组。奇数分组先得到，偶数再做）
	
>3.最接近的数([CC150 Q27](https://www.nowcoder.com/practice/33ad4d168a3247b9b63f41e4eaded652?tpId=8&tqId=11021&rp=1&ru=%2Fta%2Fcracking-the-coding-interview&qru=%2Fta%2Fcracking-the-coding-interview%2Fquestion-ranking&tPage=2))([CC150 Sol](http://hawstein.com/2013/01/04/5.3/))

	方法1: 对于0001100，更大的一个数是另左边第二次出现连续的0时成为1,后面补0->0010000
		再将后面多加不足的1->0010001. 整个过程为x + 1<<c_0 + 1<<(c_01-1) - 1,c_0=2,c_01=2
		对于1100011，更小的一个数是另左边第二次出现连续的1时成为0，后面补1->1011111
		再将后面多余的1变成0->1011100. 整个过程为x - (1<<c_1) - 1<<(c_10-1) + 1, c_1=2,c_10=3
	
>4.交换奇偶数位([CC150 Q29](https://www.nowcoder.com/practice/ed7d014b42e740679c4bd69b9d9c49b9?tpId=8&tqId=11023&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2013/01/04/5.6/))
	
	方法1: 用mask表示奇数与偶数(0x55555555, 0xAAAAAAAA). 输出(odd<<1 | even>>1)
	
>5.集合的子集([CC150 Q43](https://www.nowcoder.com/practice/1f2700e2b1904254b55765479e9b8766?tpId=8&tqId=11037&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2013/01/10/8.3/))
	
	方法1: 一个集合的全排列可以用n个1表示，则最大为2^n-1, 最小为1(非空子集)。按照位置加入元素即可
	复杂度： O(1) space, O(n) time.
	
---
<br />


# <h2 id="12">动态规划（Dynamic Programming）</h2>
### 问题及思路

> 1.斐波拉契数列 ([剑指offer Q7](https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: for loop 动态计算后面的值，注意溢出，long long保存结果
	复杂度： O(1) space, O(n) time.
	相关： 青蛙跳， 矩形覆盖

> 2.连续子数组的最大和 ([剑指offer Q30](https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 使用一个额外的sum保存到该数的最大sum。如果sum为负则定义改出的sum为自身（最大sum必然不包括前面的负数和）
	复杂度： O(1) space, O(n) time.
	相关问题：最大和子矩阵[CC150 Q81]: 每次将i～j行加起来，求连续字数组最大和。O(n)space，O(n^3) time.

> 3.连续子数组的最大积 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/05.01.html))

	方法1: 由于有负数的存在，同时需要保存有负数的情况。
			状态转移: max[i] = max(max[i-1]*A[i], min[i-1]*A[i], A[i]) -> 结果在此数组中更新
					 min[i] = min(max[i-1]*A[i], min[i-1]*A[i], A[i])
	复杂度： O(n) space (O(1) if you use two var only), O(n) time.

> 4.字符串的最小编辑距离 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/05.02.html))

	方法1: dp[i][j]表示从S[:i]到T[:j]的转换. dp[i][0]=i; dp[0][j]=j.
			状态转移: dp[i][j] =min{
					dp[i-1][j] + 1, S[i]不在T[0…j]中，删除操作
					dp[i-1][j-1] + 1/0, S[i]是否等于0T[j]，替换操作
					dp[i][j-1] + 1 , S[i]在T[0…j-1]中增加操作
			即 dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (S[i]==T[j]))
	复杂度： O(nm) space, O(mn) time.

> 5.交替字符串 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/05.04.html))

	方法1: dp[i][j]表示C[:i+j]由A[:i], B[:j]交替而得
			状态转移: dp[i][j] = 1 if:
							dp[i][j-1]==1 && C[i+j]==B[j] ||
							dp[i-1][j]==1 && C[i+j]==A[i]
					dp[i][j] = 0 otherwise
	复杂度： O(nm) space, O(nm) time.

> 6.最长递增子序列 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/05.06.html))

	方法1: dp[i]表示以A[i]结尾的序列的最长递增子序列. dp[0]=1
			状态转移: dp[j] = max(A[i] for 0<=i<j and A[i]<A[j]). If not exist. A[j]=0
	复杂度： O(n) space, O(n^2) time.
	相关问题：最长公共子序列
				Xm=Yn -> LCS(m,n)=LCS(m-1,n-1)+1; 
				Xm!=Yn -> LCS(m,n)=max{LCS(m-1,n)+LCS(m,n-1)}
	
> 7.硬币组合 ([CC150 Q47](hhttps://www.nowcoder.com/practice/c0503ca0a12d4256af33fce2712d7b24?tpId=8&tqId=11041&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](https://www.cnblogs.com/python27/archive/2013/09/05/3303721.html))

	不能直接使用dp进行规划，因为没有分硬币种类dp的时候会重复计算组合
	方法1: dp[m][sum]表示前m个硬币组成sum的方法数。
			状态转移: dp[m] = dp[m-1][sum-k*coins[m]] for k=0,...,sum/coins[m]. 
			实际递归的时候可以用dp[m-1][sum]+dp[m][sum-coins[m]],但要保证sum>=coins
	复杂度： O(kn) space, O(kn) time.
	
	方法2: 同方法1，但是可以只用一个O(n)的vec表示，每次加入新的coin只更新coins[m]~n的这部分，转移函数为
			dp[j] = (dp[j]+dp[j-coins[i]]), for j=coins[i]~n, for i=1~4. dp[0]=0
	复杂度： O(n) space, O(kn) time.
	
> 8.堆箱子的最大高度 ([CC150 Q48](https://www.nowcoder.com/practice/daaec37090484f4587d0e8f5b612cda1?tpId=8&tqId=11043&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 先将w, l, h都按照w的降序排列，然后求l中h最大递减子序列。同6中的方法
	复杂度： O(n) space, O(n^2) time.
	相关问题：最长递增子序列
	
> 9.最大子方阵 ([CC150 Q80](https://www.nowcoder.com/practice/008759ec032e44c6b615f7b6a5b752aa?tpId=8&tqId=11074&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 暴力查找以每个顶点每个长度组成的方阵是否满足要求
	复杂度： O(1) space, O(n^3) time.
	
	方法2: 用两个dp矩阵保存到某点的左边和上面的最长相等长度。可用dp来计算。
	      求解时逐步遍历长度找到相对应的左和上点判断其上/左长度是否满足。
	复杂度： O(^2) space, 最差O(n^3) time，但会稍好.


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

> 4.不使用加减乘除和判断语句求1～n的和([剑指offer Q47](https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 采用递归. n==0时 n && 不再计算直接返回
	复杂度： O(1) space, O(logn) time.
	 int res = n;
     n && (res += Sum_Solution(n-1));
     return res;

> 5.不用加减乘除做加法([剑指offer Q48](https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 位运算。xor为sum， and 与 <<1为carry。直到carry不为0

> 6.二进制float小数([CC150 Q26](https://www.nowcoder.com/practice/743853af75fc4026939a682b86535f79?tpId=8&tqId=11020&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2013/01/02/5.2/))

	方法1: 整数部分通过%2再/2一步步向前，小数部分对比1/2^i一步步向后
	
> 7.无缓存交换([CC150 Q60](https://www.nowcoder.com/practice/845ec89145b04b2b855d020d9c3ea2ef?tpId=8&tqId=11054&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2013/02/20/19.1/))

	方法1: b = a - b
		  a = a - b = b
		  b = a + b = a
	
	方法2: a = a^b
		  b = a^b = a^b^b = a
		  a = a^b = a^b^a = b
		  
> 8.得到两数较大值([CC150 Q62](https://www.nowcoder.com/practice/b0a82250677a4fabb0bc41053fa05013?tpId=8&tqId=11056&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2013/02/21/19.4/))

	方法1: b = a - b，令b>>31为mask.如果a<b,mask=11..11; 否则mask=00..00
		   b&(b>>31) = a-b if a<b else 0. 返回 a-b&(b>>31) 即可
		   
> 9.阶乘末尾0的个数([CC150 Q64](https://www.nowcoder.com/practice/434922f9f4724b97b83c417e884008f1?tpId=8&tqId=11058&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))([CC150 Sol](http://hawstein.com/2013/02/20/19.3/))

	方法1: 等同于只需要计算5的因子数。n/5返回1一个5的个数，/25返回两个5的额外个数。所以loop让n/=5不停统计即可
	复杂度： O(1) space, O(logn) time.

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
### 十大排序算法
参考地址([blog](https://www.cnblogs.com/onepixel/p/7674659.html))

不稳定的算法：选择排序/快速排序/堆排序/希尔排序 （基本是因为不相邻的交换导致）

> 1.冒泡排序(Bubble Sort) <br>
>
> 简述：每次将最大的数冒泡至最后 <br>
> 平均时间复杂度: O(n^2) <br>
> 最差时间复杂度: O(n^2) <br>
> 空间复杂度: O(1) <br>
> 稳定性: 稳定，因为冒泡时相同数字不交换

	int len = nums.size()
	int temp = 0;
	for (int i = 0; i < len - 1; i++) {
	    for (int j = 0; j < len - 1 - i; j++) {
	        if (nums[j] > nums[j+1]) {
	            temp = nums[j+1];
	            nums[j+1] = nums[j];
	            nums[j] = temp;
	        }
	    }
	}

> 2.选择排序(Selection Sort) <br>
>
> 简述：每次挑选出剩余数组中最小的数，交换至开头 <br>
> 平均时间复杂度: O(n^2) <br>
> 最差时间复杂度: O(n^2) <br>
> 空间复杂度: O(1) <br>
> 稳定性: 不稳定，因为交换的时候可能会把原本顺序打乱（用链表稳定因为直接插入开头不需要交换）

	int minIndex=0, temp=0;
	int len = nums.size()
	for (int i = 0; i < len - 1; i++) {
	    minIndex = i;
	    for (int j = i + 1; j < len; j++) {
	        if (nums[j] < nums[minIndex]) {
	            minIndex = j;
	        }
	    }
	    temp = nums[i];
	    nums[i] = nums[minIndex];
	    nums[minIndex] = temp;
	}

> 3.插入排序(Insertion Sort) <br>
>
> 简述：每次挑选出剩余数组中最小的数，交换至开头 <br>
> 平均时间复杂度: O(n^2) <br>
> 最差时间复杂度: O(n^2) <br>
> 空间复杂度: O(1) <br>
> 稳定性: 稳定，因为插入从后面进行，相同数字只会插到后面

	int key = 0;
	int j = 0;
	for(int i=1; i<nums.size(); i++){
		key = nums[i];
		j = i-1;
		while(j>0 && nums[j]>key){
			nums[j+1]=nums[j];
			j--;
		}
		nums[j+1] = key;
	}

> 4.快速排序(Quick Sort) <br>
>
> 简述：每次选取最后一个数作为pivot，小的放前面，大的放后面，再递归 <br>
> 平均时间复杂度: O(nlogn) <br>
> 最差时间复杂度: O(n^2) -- 当本来就排好序时 <br>
> 空间复杂度: O(logn) --递归导致 <br>
> 稳定性: 不稳定，交换pivot时可能把中间位置的数移动改变顺序

	void quickSort(vector<int>& nums){
		quickSort(nums,0,nums.size());
	}
	void quickSort(vecotr<int>& nums, int low, int high){
		if(low<high){
			int p = partition(nums,low,high);
			quickSort(nums,low,p-1);
			quickSort(nums,p,high);
		}
	}
	int partition(vector<int>& nums,int low, int high){
		int pivot = nums[high];
		int i=low-1;
		for(int j=low;j<high;j++){
			if(nums[j]<=pivot){
				swap(nums[++i],nums[j]);
			}
		}
		swap(nums[++i],nums[high]);
		return i;
	}

> 5.归并排序(Merge Sort) <br>
>
> 简述：每次递归merge两个排好序的数列 <br>
> 平均时间复杂度: O(nlogn) <br>
> 最差时间复杂度: O(nlogn) <br>
> 空间复杂度: O(n) <br>
> 稳定性: 稳定

	void merge(vector<int>& arr, int first, int mid, int last){
		vector<int> l,r;
		for(int i=first;i<mid;i++) l.push_back(arr[i]);
		for(int i=mid+1;i<last;i++) r.push_back(arr[i]);
			int a=0,b=0;
		for(int k=first;k<last;k++){
			if(b==r.size()) {arr[k]=l[a++];}
			else if (a==l.size()) rr[k]=r[b++];
			else if(l[a]<=r[b]){arr[k]=l[a++];}
			else{arr[k]=r[b++];}
		}
	}
	void mergeSort(vector<int>& arr, int first, int last){
		if(first<last){
			int mid = (first + last) /2
			mergeSort(arr,first,mid);
			mergeSort(arr,mid+1,last);
			merge(arr,first,mid,last);
		}
	}

> 6.堆排序(Heap Sort) <br>
>
> 简述：构建一个最大堆，每次将堆顶数字与尾部数字交换 <br>
> 平均时间复杂度: O(nlogn) <br>
> 最差时间复杂度: O(nlogn) <br>
> 空间复杂度: O(1) <br>
> 稳定性: 不稳定

	 Pass

> 7.希尔排序(Shell Sort) <br>
>
> 简述：缩小增量排序，每次按照不同的gap分组排序,组内插入排序 <br>
> 平均时间复杂度: O(nlogn) <br>
> 最差时间复杂度: O(n^2) -- 当本来就排好序时 <br>
> 空间复杂度: O(1) <br>
> 稳定性: 不稳定，不同组内排序的交换可能打乱顺序

	Pass

> 8.计数排序(Counting Sort) <br>
>
> 简述：当数字范围有限时，记录每个数字出现记录 <br>
> 平均时间复杂度: O(n+m) <br>
> 最差时间复杂度: O(n+m) <br>
> 空间复杂度: O(n+m) <br>
> 稳定性: 稳定

	Pass

> 9.桶排序(Bucket Sort) <br>
>
> 简述：使用多个桶，将数字放到不同的桶里，分别排序。桶的分组有顺序，merge按顺序即可 <br>
> 平均时间复杂度: O(n) <br>
> 最差时间复杂度: O(n) <br>
> 空间复杂度: O(m) <br>
> 稳定性: 稳定

	Pass

> 10.基数排序(Radix Sort) <br>
>
> 简述：按照低位先排序，再依次按照高位排序 <br>
> 平均时间复杂度: O(kn)，k为位数 <br>
> 最差时间复杂度: O(n^2) <br>
> 稳定性: 稳定



---
<br />

# <h2 id="16">大数据问题（Big Data）</h2>
### 常见方法
1.hash进行分块求解（通常适用于内存不够的情况）/ 或者直接分段

2.使用堆求最大的k 相关问题

3.map-reduce

4.Locality Sensetive Hashing(LSH)

5.随机算法(Randomized Algorithm)

6.bitmap

7.Bloom Filter

8.字典树(Trie)

9.Count-Min Sketch
### 问题及思路

> 1.海量日志数据，提取出某日访问百度次数最多的那个IP([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.02.html))

	数量过多，内存中无法放进全部。采用hash分而治之。
	通过日期将ip提取，hash到每个机器上分别统计
	取出每个机器上最大的结果（因为已经hash过了，相同ip都在同一个机器上）。可使用最大堆

> 2.寻找热门查询，300万个查询字符串中统计最热门的10个查询([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.02.html))

	内存中可以全部放的下。先通过O(n)扫描统计每个查询的次数。再用堆维护
	时间为O(N) + N'*O(logk)， N'为去除重复之后的个数
	相关问题：统计词频最高的100个词（也可使用Trie树），100万个数中最大的100个数

> 3.海量数据分布在100台电脑中，想个办法高效统计出这批数据的TOP10([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.02.html))

	由于数据已经分散。
	方法1: 重新遍历，再hash分配，再用max heap
	方法2: map-reduce，在每块上分别统计，再统一在一起求出现次数

> 4.2.5亿个整数中找出不重复的整数的个数，内存空间不足以容纳这2.5亿个整数([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.06.html))

	将数据分为多个区域（如2^8），每个中使用bitmap统计，内存够用（每个bit代表一个数字）

> 5.5亿个int找它们的中位数([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.06.html))

	将数据从大到小分到不同的机器中。从小机器开始统计个数，不断累加，知道到达中位数

> 6.10万个长度不超过10的单词判断前面是否出现过([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.09.html))

	1.构建一个trie树（26叉树），每遇到一个词，插入和查询可以一起进行，都是O(1)时间（因为长度为10）
	2.允许错误时也可以用bloom filter

> 7.两个大文件是否有相同url([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.08.html))

	1.若允许一定的错误率，可以使用bloom filter。将一个文件中的url全部映射到全部内存表示的bits（4G->340亿bit）中。在扫描第二个文件，使用filter看是否存在
	2.可将文件1的url通过hash放到多个小文件中，然后将文件2遍历看是否在存在的小文件中

> 8.数据流采样/蓄水池算法 [Blog](https://soulmachine.gitbooks.io/system-design/content/cn/bigdata/data-stream-sampling.html)

	从stream中随机抽取k个整数。
	- 当前k个到达时，全部保留
	- 当第i>k个整数到达时，以k/i的概率丢弃任意一个留下的整数
	- 归纳法可证明所有整数留下的概率相同

> 9.频率估计 [Blog](https://soulmachine.gitbooks.io/system-design/content/cn/bigdata/frequency-estimation.html)

	使用count-min sketch。用多个hash table保存。
	多个数字可以进入到一个hash bucket中，每次进入都在此bucket加1。当求一个数字的频率时，可求该bucket的值，返回误差在可接受范围内的值

> 10.元素计数 [Blog](http://www.mit.edu/~andoni)

	设一个值X=0. 对每个新来的值，X+=1 with Pr=1/2^X,不然不变。
	返回2^X-1. 可用归纳法证明E(2^X-1)=n. 且variance小。用median trick可保证90%准确率。

<br />

# <h2 id="17">其他（Other）</h2>
## 操作系统
### 问题及思路
来自([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/08.04.html))

> 1.请问死锁的条件是什么？

	互斥条件（Mutual exclusion）：
	1、资源不能被共享（No Sharable），只能由一个进程使用。
	2、请求与保持条件（Hold and wait）：已经得到资源的进程可以再次申请新的资源。
	3、非剥夺条件（No pre-emption）：已经分配的资源不能从相应的进程中被强制地剥夺。
	4、循环等待条件（Circular wait）：系统中若干进程组成环路，该环路中每个进程都在等待相邻进程正占用的资源。

> 2.如何处理死锁问题：

	1、忽略该问题。例如鸵鸟算法，该算法可以应用在极少发生死锁的的情况下。为什么叫鸵鸟算法呢，因为传说中鸵鸟看到危险就把头埋在地底下，可能鸵鸟觉得看不到危险也就没危险了吧。跟掩耳盗铃有点像。
	2、检测死锁并且恢复。
	3、仔细地对资源进行动态分配，以避免死锁。
	4、通过破除死锁四个必要条件之一，来防止死锁产生。

> 3.请阐述进程与线程的区别。

	①从概念上：
		进程：一个程序对一个数据集的动态执行过程，是分配资源的基本单位。
		线程：一个进程内的基本调度单位。线程的划分尺度小于进程，一个进程包含一个或者更多的线程。
	②从执行过程中来看：
		进程：拥有独立的内存单元，而多个线程共享内存，从而提高了应用程序的运行效率。
		线程：每一个独立的线程，都有一个程序运行的入口、顺序执行序列、和程序的出口。但是线程不能够独立的执行，必须依存在应用程序中，由应用程序提供多个线程执行控制。
	③从逻辑角度来看（重要区别）：
		多线程的意义在于一个应用程序中，有多个执行部分可以同时执行。但是，操作系统并没有将多个线程看做多个独立的应用，来实现进程的调度和管理及资源分配。

> 4.用户进程间通信主要哪几种方式？

	主要有以下6种：

	1、管道：管道是单向的、先进先出的、无结构的、固定大小的字节流，它把一个进程的标准输出和另一个进程的标准输入连接在一起。写进程在管道的尾端写入数据，读进程在管道的道端读出数据。数据读出后将从管道中移走，其它读进程都不能再读到这些数据。管道提供了简单的流控制机制。进程试图读空管道时，在有数据写入管道前，进程将一直阻塞。同样地，管道已经满时，进程再试图写管道，在其它进程从管道中移走数据之前，写进程将一直阻塞。
		- 无名管道：管道是一种半双工的通信方式，数据只能单向流动，而且只能在具有亲缘关系（通常是指父子进程关系）的进程间使用。
		- 命名管道：命名管道也是半双工的通信方式，在文件系统中作为一个特殊的设备文件而存在，但是它允许无亲缘关系进程间的通信。当共享管道的进程执行完所有的I/O操作以后，命名管道将继续保存在文件系统中以便以后使用。
	2、信号量：信号量是一个计数器，可以用来控制多个进程对共享资源的访问。它常作为一种锁机制，防止某进程正在访问共享资源时，其它进程也访问该资源。因此，主要作为进程间以及同一进程内不同线程之间的同步手段。
	3、消息队列：消息队列是由消息的链表，存放在内核中并由消息队列标识符标识。消息队列克服了信号传递信息少、管道只能承载无格式字节流以及缓冲区大小受限等缺点。
	4、信号：信号是一种比较复杂的通信方式，用于通知接收进程某个事件已经发生。
	5、共享内存：共享内存就是映射一段能被其它进程所访问的内存，这段共享内存由一个进程创建，但多个进程都可以访问。共享内存是最快的IPC方式，它是针对其它进程间通信方式运行效率低而专门设计的。它往往与其它通信机制（如信号量）配合使用，来实现进程间的同步和通信。
	6、套接字：套接字也是一种进程间通信机制，与其它通信机制不同的是，它可用于不同机器间的进程通信

> 5.虚拟内存

	虚拟内存是计算机系统内存管理的一种技术。它使得应用程序认为它拥有连续的可用的内存 （一个连续完整的地址空间），
	而实际上，它通常是被分隔成多个物理内存碎片， 还有部分暂时存储在外部磁盘存储器上，在需要时进行数据交换。 
	与没有使用虚拟内存技术的系统相比，使用这种技术的系统使得大型程序的编写变得更容易， 对真正的物理内存（例如RAM）的使用也更有效率。
	
> 6.缺页中断

	一个页(Page)是一个固定容量的内存区块，是物理内存和外部存储(如硬盘等) 传输的单位。当一个程序访问一个映射到地址空间却实际并未加载到物理内存的页（page）时， 硬件向软件发出的一次中断（或异常）就是一个缺页中断或叫页错误（page fault）。

## 计算机网络
### 问题及思路
来自([CC150](http://hawstein.com/2013/03/14/ctci-solutions-contents/))
> 1.往浏览器中输入一个URL后都发生了什么：

	1.浏览器向DNS服务器查找输入URL对应的IP地址。
	2.DNS服务器返回网站的IP地址。
	3.浏览器根据IP地址与目标web服务器在80端口上建立TCP连接
	4.浏览器获取请求页面的html代码。
	5.浏览器在显示窗口内渲染HTML。
	6.窗口关闭时，浏览器终止与服务器的连接。

## 编译
### 问题及思路
来自([github](https://github.com/lawy623/interview))

> 1.编译链接过程：

	1. 预编译（预编译器处理如 #include、#define 等预编译指令，生成 .i 或 .ii 文件）
	2. 编译（编译器进行词法分析、语法分析、语义分析、中间代码生成、目标代码生成、优化，生成 .s 文件）
	3. 汇编（汇编器把汇编码翻译成机器码，生成 .o 文件）
	4. 链接（连接器进行地址和空间分配、符号决议、重定位，生成 .out 文件）

> 2.内存、栈、堆

	一般应用程序内存空间有如下区域：

	- 栈：由操作系统自动分配释放，存放函数的参数值、局部变量等的值，用于维护函数调用的上下文
	- 堆：一般由程序员分配释放，若程序员不释放，程序结束时可能由操作系统回收，用来容纳应用程序动态分配的内存区域
	- 可执行文件映像：存储着可执行文件在内存中的映像，由装载器装载是将可执行文件的内存读取或映射到这里
	- 保留区：保留区并不是一个单一的内存区域，而是对内存中受到保护而禁止访问的内存区域的总称，如通常 C 语言讲无效指针赋值为 0（NULL），因此 0 地址正常情况下不可能有效的访问数据

> 3.请阐述动态链接库与静态链接库的区别。

	- 静态链接库是.lib格式的文件，一般在工程的设置界面加入工程中，程序编译时会把lib文件的代码加入你的程序中因此会增加代码大小，你的程序一运行lib代码强制被装入你程序的运行空间，不能手动移除lib代码。
	- 动态链接库是程序运行时动态装入内存的模块，格式*.dll，在程序运行时可以随意加载和移除，节省内存空间。
	- 在大型的软件项目中一般要实现很多功能，如果把所有单独的功能写成一个个lib文件的话，程序运行的时候要占用很大的内存空间，导致运行缓慢；但是如果将功能写成dll文件，就可以在用到该功能的时候调用功能对应的dll文件，不用这个功能时将dll文件移除内存，这样可以节省内存空间。

## C++
### 问题及思路
来自([github](https://github.com/lawy623/interview))([CC150](http://hawstein.com/2013/03/14/ctci-solutions-contents/))

> 1.const 作用

	1.修饰变量，说明该变量不可以被改变；
	2.修饰指针，分为指向常量的指针和指针常量；
		- const int *A; //const修饰指向的对象，A可变，A指向的对象不可变
		- int const *A; //const修饰指向的对象，A可变，A指向的对象不可变
		- int *const A; //const修饰指针A， A不可变，A指向的对象可变
		- const int *const A;//指针A和A指向的对象都不可变
	3.常量引用，经常用于形参类型，即避免了拷贝，又避免了函数对值的修改；
	4.修饰成员函数，说明该成员函数内不能修改成员变量。

> 2.static 作用

	1.修饰普通变量，修改变量的存储区域和生命周期，使变量存储在静态区，在 main 函数运行前就分配了空间，如果有初始值就用初始值初始化它，如果没有初始值系统用默认值初始化它。
	2.修饰普通函数，表明函数的作用范围，仅在定义该函数的文件内才能使用。在多人开发项目时，为了防止与他人命名空间里的函数重名，可以将函数定位为 static。
	3.修饰成员变量，修饰成员变量使所有的对象只保存一个该变量，而且不需要生成对象就可以访问该成员。static成员必须在类外进行初始化
	4.修饰成员函数，修饰成员函数使得不需要生成对象就可以访问该函数，但是在 static 函数内不能访问非静态成员。

> 3.虚函数、纯虚函数

	1.类里如果声明了虚函数，这个函数是实现的，哪怕是空实现，它的作用就是为了能让这个函数在它的子类里面可以被覆盖，这样的话，编译器就可以使用后期绑定来达到多态了。纯虚函数只是一个接口，是个函数的声明而已，它要留到子类里去实现。
	2.虚函数在子类里面也可以不重载的；但纯虚函数必须在子类去实现。
	3.虚函数的类用于 “实作继承”，继承接口的同时也继承了父类的实现。当然大家也可以完成自己的实现。纯虚函数关注的是接口的统一性，实现由子类完成。
	4.带纯虚函数的类叫抽象类，这种类不能直接生成对象，而只有被继承，并重写其虚函数后，才能使用。抽象类被继承后，子类可以继续是抽象类，也可以是普通类。
	5.虚基类是虚继承中的基类，具体见下文虚继承。
	
> 4.C++中的虚函数是如何工作的？

	1.虚函数依赖虚函数表进行工作。如果一个类中，有函数被关键词virtual进行修饰，那么一个虚函数表就会被构建起来保存这个类中虚函数的地址。
	2.同时，编译器会为这个类添加一个隐藏指针指向虚函数表。如果在派生类中没有重写虚函数，那么，派生类中虚表存储的是父类虚函数的地址。
	3.每当虚函数被调用时，虚表会决定具体去调用哪个函数。因此，C++中的动态绑定是通过虚函数表机制进行的。
	
> 5.深拷贝和浅拷贝的区别是什么？你会如何使用它们？

	浅拷贝并不复制数据，只复制指向数据的指针，因此是多个指针指向同一份数据。 
	深拷贝会复制原始数据，每个指针指向一份独立的数据。
	
> 6.谈谈C语言关键字”volatile”的意义(或重要性)？

	volatile的意思是”易变的”，因为访问寄存器比访问内存要快得多，所以编译器一般都会做减少存取内存的优化。
	volatile 这个关键字会提醒编译器，它声明的变量随时可能发生变化(在外部被修改).
	因此，与该变量相关的代码不要进行编译优化，以免出错。


---
<br />
