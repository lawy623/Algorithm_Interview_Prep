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
int *ptr = new int[n]                 ## init array with size n
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
sort(vec.begin(), vec.end());                               ## sort the vector - increasing
sort(vec.begin(), vec.end(), greater<int>);                 ## sort the vector - decreasing
    static bool comp(int a, int b)                          ## sort by self defined static cmp func
    sort(v.begin(), v.end(), comp)
for (auto x : vec) {}                                       ## access by auto var though the vector
vector<int>::iterator it;                                   ## create iterator
    for(it=vec.begin(); it!=vec.end(); it++) {cout<<*it}    ## loop through using iterator, *it is the val
vec.insert(vec.begin()+i, x)                                ## insert x at i+1 pos
vec.erase(vec.begin()+i)                                    ## remove the i+i val
vec.erase(vec.begin()+i, vec.begin()+j)                     ## remove from i+1 to j
reverse(vec.begin(), vec.end())                             ## reverse the vector
vec2.assign(vec1.begin(), vec2.begin())                     ## copy vec1's value to vec2
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
> 1_1.旋转数组的最小数字 ([剑指offer Q6](https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)) ([Leetcode Q154](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/))

	方法1: 直接扫描，当后面小于前面则返回
	复杂度： O(1) space, O(n) time.
	
	方法2: 二分查找。每次对比mid与头尾的值。注意start一定大于等于end，否为不为旋转数组而是排序数组
	最主要的是中间和两头判断的corner case
	· mid == end && mid == start, 则查找[start+1, end-1] <--(注意[1,0,1,1,1]与[1,1,1,0,0]的特殊case)
	· mid>end, 则查找[mid+1, end];
	· 其他情况,则查找[start, mid]
    注意的就是： 合理的左中右三种情况，只要中间比右小， 就可以往左边放缩
	复杂度： O(1) space, O(logn) time.

> 1_2.搜索排序旋转数组 ([Leetcode Q33](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/))

    方法1: 按照mid与l的值比较
            如果mid>=l, 证明在左侧上升序列。只有当target的值在l和mid中间才往(l,mid-1)搜，否则往(mid+1,r)搜
            否则在右侧上升序列。只有当target的值在r和mid中间才往(mid+1，r)搜，否则往(l,mid-1)搜
            与边界值的判断都要带等号
    将其想像成：两组上升的序列，找到mid所属哪边，再用二分法查找
	复杂度： O(1) space, O(logn) time.
	
> 1_3.查找峰值 ([Leetcode Q162](https://leetcode-cn.com/problems/find-peak-element/))

    方法1: 二分查找。当nums[m] > nums[m+1]时，峰值一定在l~m, 否则单调递减l就是峰值
                  否则m一定在m+1~r, 否则单调递增r就是峰值
	复杂度： O(1) space, O(logn) time.

> 2.调整数组顺序使奇数位于偶数前面 ([剑指offer Q13](https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof))

	方法1: 直接扫描，分别保存奇数与偶数数组，再合并
	复杂度： O(n) space, O(n) time.
	
	方法2: 冒泡排序的方法，每次前为偶数后卫奇数则交换，每次把偶数放到最后
	复杂度： O(1) space, O(n^2) time.
	
	方法3: 双指针，从头和尾分别遍历。当前为偶数后为奇数时交换。否则向中间移动指针
	复杂度： O(1) space, O(n) time.
	
	方法4: 快排方式。遇到奇数则交换
	复杂度： O(1) space, O(n) time.

> 3_1.数组中出现次数超过一半的数字 ([剑指offer Q28](https://leetcode-cn.com/problems/shu-zu-zhong-chu-xian-ci-shu-chao-guo-yi-ban-de-shu-zi-lcof)) ([Leetcode Q169](https://leetcode-cn.com/problems/majority-element))

	方法1: 排序，在找median的值。需要判断该值是否真的出现超过一半次数（出现超过一半必为排序中位数，但中位数未必超过一半）
	复杂度： O(1) space, O(nlogn) time.
	
	方法2: 使用最大/最小堆。构建堆，再推出找到中位数
	复杂度： O(n) space, O(n+klogn) time. 当n>>k时效率高
	
	方法3: QuickSelect通过找到第k小的数找到中位数
	复杂度： O(1) space, O(n) time（On average）.
	
	方法4： 摩尔投票。通过count，超过半数的一定保留着最后的val
	复杂度： O(1) space, O(n) time
	
> 3_2.数组中出现次数超过1/3的数字 ([Leetcode Q229](https://leetcode-cn.com/problems/majority-element-ii))

    方法1： 摩尔投票。最多只会有两个数超过1/3，用两个count和val记录遇到的数字。如果都不对上，count都要减1
           最后需要判断两个值是否都超过1/3. 由于初始值的关系，全0会导致两个值都为0，需要排除
	复杂度： O(1) space, O(n) time

> 4.最小的K个数 ([剑指offer Q29](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/))

	方法1: 使用最小堆。构建堆，再推出直到第k个数
	复杂度： O(n) space, O(n+klogn) time. 当n>>k时效率高

	方法2: QuickSelect通过找到第k小的数找到中位数。同快排，通过partition找到中间pivot的位置
			如果pivot是第k个则返回。大于k则partition前面的数组，小于k则partition后面的数组
	复杂度： O(1) space, O(n) time（On average, worst O(n^2)）.

> 5.把数组排成最小的数 ([剑指offer Q32](https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof))

	方法1: 定义一种排序方式。当“前+后”比“后+前”小时，前<后。排序后返回即可
			需要证明该排序定义的A1A2A3....An是最小的。可用反证法证明
	复杂度： O(1) space, O(nlogn) time.

> 6.数组中的逆序对 ([剑指offer Q35](https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/))

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

> 8_1.和为S的两个数字 ([剑指offer Q42](https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof)) ([Leetcode Q1](https://leetcode-cn.com/problems/two-sum/))

	方法1: 排序后使用前后两个pointer查找
	复杂度： O(1) space, O(nlogn) time.
	
	方法2: 使用hash。保存遍历的数字，新数字判断差值是否在hash中
	复杂度： O(n) space, O(n) time.

> 8_2.和为S的三个数字 ([Leetcode Q15](https://leetcode-cn.com/problems/three-sum/))

	方法1: 排序后, 固定第一个位置，后面用双指针使用前后两个pointer查找。需要注意重复的情况
	复杂度： O(1) space, O(n^2+nlogn) time.
	相似题目：最接近target的三数之和([Leetcode Q16])：注意更新jk的时候按照sum和target的大小更新

> 9_1.和为S的连续正数序列 ([剑指offer Q41](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/))

	方法1: 前后双指针。根据和的情况分别移动两个指针。
	复杂度： O(1) space, O(n) time.
	
> 9_2.和为K的连续子数组 ([Leetcode Q560](https://leetcode-cn.com/problems/subarray-sum-equals-k/))

	方法1: 每个ij区间求和判断，可优化至O(n^2)
	复杂度： O(1) space, O(n^2) time.
	
	方法2: 注意连续数组和(i,j)=sum(0,j)-sum(0,i)。可以用一个dict保存sum(i)的个数。每次更新dict。
	      对于j位置来说，count新增 dict[sum(j)-k]次
	复杂度： O(n) space, O(n) time.
	
> 9_3.和为K倍数的连续子数组 ([Leetcode Q523](https://leetcode-cn.com/problems/continuous-subarray-sum/))
	
	方法1: dict保存对k的余数，当余数相同时，子数组和为k的倍数。为了保证数组长度至少为2，dict[sum%k]>((sum%k)==(prev_sum%k))
	复杂度： O(n) space, O(n) time.

> 10.扑克牌顺子 ([剑指offer Q45](https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/))

	方法1: 先排序，计算大小王（0）的个数，当n_0<4时，剩余的最大值-最小值<=4.（注意判断数值是否在[0,13]）
	复杂度： O(1) space, O(1) time.

> 11_1.数组中重复的数字 ([剑指offer Q50](https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/)) ([Leetcode Q287](https://leetcode-cn.com/problems/find-the-duplicate-number/))

	方法1: 使用hash table储存，直到遇到第一个重复的数字
	复杂度： O(n) space, O(n) time.
	
	方法2: 将每个数字i移动到第i个位置, 如果num[i]和nums[nums[i]]重复了话则输出该值。（如果是1-n的数，要用nums[nums[i]-1]）
	复杂度： O(1) space, O(n) time.
	相似问题: 魔术引索([CC150 Q42]-当A[i]>i时，i直接跳到A[i]，避免无用搜索
	
> 11_2.数组中缺失的数字 ([Leetcode Q448](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array))

	方法1: 使用hash table储存，遍历之后看看dict是否已经记录了
	复杂度： O(n) space, O(n) time.
	
	方法2: 遍历每个值，将该值对应的nums位置设置成负数。重新遍历，为正的位置预示着这个数字没出现过
	复杂度： O(1) space, O(n) time.
	相似题目：丢失的数字 ([Leetcode 268])因为刚好有一个数字恰好缺失一次，直接计算n*n+1 / 2 - sum即可
	
> 11_3.第一个缺失的正数 ([Leetcode Q41](https://leetcode-cn.com/problems/first-missing-positive/))

	方法1: 使用hash table储存，遍历之后看看dict是否已经记录了
	复杂度： O(n) space, O(n) time.
	
	方法2: 将数组本身当作一个hash table。第一个缺失的正数一定在[1,n+1]内。先把负数改成n+1, 遍历数组。
	      当数的绝对值<n+1时，将对应的hash table设置为负数。再遍历一次就知道谁不在里面了
	复杂度： O(1) space, O(n) time.

> 12.不用除法构建乘积数组 ([剑指offer Q51](https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/))

	方法1: 暴力构建，两个for loop
	复杂度： O(1) space, O(n^2) time.
	
	方法2: 用两个数组分别表示从左/右开始到某位置i的累积乘积，dp方式求解
	复杂度： O(n) space, O(n) time.
	
	方法3: 只用一个输出vector记录，左右对该结果vec进行更新
	复杂度： O(1) space, O(n) time.
	
> 13.荷兰旗问题（三色分离）([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/02.07.html)) ([Leetcode Q75](https://leetcode-cn.com/problems/sort-colors/))

	方法1: Sorting counting
	复杂度： O(1) space, O(n) time.
	
	方法1: 类似快速排序。使用三个指针l1,l2,l3。l1&l2指向头，l3指向尾
			当l2==0时，交换l1，l2的值，l1,l2各加1
			当l2==1时，l2加1
			当l2==2时，交换l3，l2的值，l3减1
			直到l2==l3
	复杂度： O(1) space, O(n) time.

> 14.最小调整有序 ([CC150 Q65](https://www.nowcoder.com/practice/091c2f1cf441484f81696f08328b06cd?tpId=8&tqId=11059&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 用两个vector分别表示从左到右的最大值/从右到左的最小值。
		从左到右遍历最小值，当最小值第一次不为自身，即右边有更小的数，一定要调整
		从右到左遍历最大值，当最大值第一次不为自身，即左边有更小的数，一定要调整
	复杂度： O(n) space, O(n) time.
	
	方法2: 不需要用vector保存所有的结果。只要记录从左到右最后一次最大值更改，和从右到左最后一次最小值更改即可。
	复杂度： O(1) space, O(n) time.

> 15.下一个最大数 ([CC150 Q73](https://www.nowcoder.com/practice/11ae41035eef4ed9b354d0752f5abc6f?tpId=8&tqId=11067&tPage=4&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 用一个stack保存从后往前的值，当检查A[i]后的第一个最大，将stack pop至找到top>A[i]，再将A[i]推进去。
		原理在于，后面比A[i]小的数都不用继续保存了，因为A[i]相对于他们总是下一个最大的数
	复杂度： O(n) space, O(n) time.
	
	方法2： 单调栈，参考栈的部分

> 16.下一个最大数II ([CC150 Q74](https://www.nowcoder.com/practice/a0c19f3489774fe693d71490ce83b648?tpId=8&tqId=11068&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 用一个set当作二叉搜索树，每次从后insert并找到upper_bound.找不到返回-1
	复杂度： O(n) space, O(logn) time插入和查找.

> 17.单词最近距离 ([CC150 Q74](https://www.nowcoder.com/practice/1a002eed40054042867eb1aa5b98fb11?tpId=8&tqId=11069&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2013/03/02/20.5/))

	方法1: 每次遇到其中一个string就更新其pos，计算dis并更新最小距离
	复杂度： O(1) space, O(n) time
	
	方法2: 如果想要对任意查找都快，可以将所有的pair调整顺序后保存进map
	复杂度： O(n^2) space, O(n^2) time 预处理，O(1) time查找

> 18.两个升序数组的中位数 ([Leetcode Q4](https://leetcode-cn.com/problems/median-of-two-sorted-arrays))

    方法1:  双指针前进，找到中位的结果，记得判断条件即可
    复杂度： O(1) space, O(m+n) time
    
    方法2: 二分查找，写起来难度较大，判断条件比较多
    复杂度： O(n+m) space, O(log(m+n)) time

> 19.有效三角形的个数 ([Leetcode Q611](https://leetcode-cn.com/problems/valid-triangle-number/))

    方法1:  排序+二分查找
    复杂度： O(logn) space, O(n^2logn) time
    
    方法2: 先排序，固定ij两个左指针时移动右指针k。找到最大满足三角形的k。移动j向右，此时k不需要重置，继续向右找，只需要两次遍历
    复杂度： O(logn) space, O(n^2) time
    
> 20.下一个排列 ([Leetcode Q31](https://leetcode-cn.com/problems/next-permutation/))

    方法1: 从右找到第一个nums[l]<nums[l+1]的位置，否则调换也是增大整个值大小
          然后再从右边找到第一个nums[k]>nums[l]的位置（最多到l+1），这样整体的提升就时最小的。
          swap l、r位置，此时l后面必然为降序数组。然后将l+1到最后的整体reverse
    复杂度： O(1) space, O(n) time
    
> 21_1.合并区间 ([Leetcode Q56](https://leetcode-cn.com/problems/merge-intervals/))

    方法1: 先将数组排序, 然后通过双指针找到最大能merge的段落（最右的start<last_end)
    复杂度： O(logn) space, O(nlogn) time
    
> 21_2.插入区间 ([Leetcode Q57](https://leetcode-cn.com/problems/insert-interval))

    方法1: 分三个阶段。
           一阶段所有的end都小于插入的start，直接往res里面push
           二阶段，直到start<=插入的end，都可以合并。注意这里相等时也可以最后合并
           三阶段，全部都push
    复杂度： O(1) space, O(n) time
    
> 22.最长连续序列 ([Leetcode Q128](https://leetcode-cn.com/problems/longest-consecutive-sequence))

    方法1: 用一个map/set保存所有的数。重新遍历时，如果a+1不在数组内，向下遍历a,a-1,...直到数组找不到。如果不加前面的条件，时间最差O(n^2)
    复杂度： O(n) space, O(n) time
    
> 23.最短无序连续子数组 ([Leetcode Q581](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/))

    方法1: 单调栈。找到最左侧nums[i] > nums[i+k]的l，找到最右侧nums[i] < nums[i-k]的r。至少需要调换lr才能满足
    复杂度： O(n) space, O(n) time
    
    方法2： 双指针。从左往右，找到最右边需要调整的边界（小于左边的最大值）
                 从右往左，找到最左边需要调整的边界（大于右边的最小值）
    复杂度： O(1) space, O(n) time

> 24.长度最小的子数组 ([Leetcode Q209](https://leetcode-cn.com/problems/minimum-size-subarray-sum/))

    方法1: 前后双指针，记录当下的sum最短的长度。注意sum一直比target小的情况
    复杂度： O(1) space, O(n) time
    
> 25.排列序列 ([Leetcode Q60](https://leetcode-cn.com/problems/permutation-sequence/))

    方法1: 每个数后面有 (n-i)！个排列。根据k/(n-i)!+1数出当前i位置最小的第？个排列。k = k % (n-i)!
    复杂度： O(n) space, O(n^2) time
 
> 26.H指数 ([Leetcode Q274](https://leetcode-cn.com/problems/h-index/))

    方法1: quicksort. 当 citation.size() - i <= citation[i]时，证明已经是最大的index了，输出citation.size()-1;
    复杂度： O(1) space, O(nlogn) time
    
    方法2：bucket sort。从大到小遍历每一个bucket，然后记录当前的h指数
    复杂度： O(max_citation) space, O(n) time
    
    方法3：二分查找。当citation[m]<=citation.size()-m时，至少有citation.size()-m满足条件，可以向左看看是否还有更大的可能。否则向右
          需要一个global value记录最大的h值（会一直变大）
    复杂度： O(1) space, O(logn) time
    
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

> 1.递增二维数组中的查找 ([剑指offer Q1](https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/)) ([Leetcode Q240](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/))

	方法1: 从右上角开始判断，小了往下， 大了往左。
	复杂度： O(1) space, O(n) time.
    相关题目: [Leetcode Q74] 二分查找矩阵化的一维升序数组

> 2_1.顺时针打印矩阵 ([剑指offer Q19](https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/)) ([Leetcode Q54](https://leetcode-cn.com/problems/spiral-matrix))

	方法1: 每次开始都是(0,0)->(1,1)->(2,2)->...->(k,k)，直到2k>=n_row或2k>=n_col
			对每个(k,k)开始的circle，四个方向找到头尾断点打印（但要判断各方向上是否需要打印。）
			
> 2_2. n^2个数顺时针输入矩阵 ([Leetcode Q59](https://leetcode-cn.com/problems/spiral-matrix-ii))

	方法1: 记录四个边的界限，每次从l->r, u->d, r->l, d->u进行输入，注意到达边界时更新新的边界

> 3.旋转矩阵 ([CC150 Q6](https://www.nowcoder.com/practice/17ab1e527c504df09a600e1af09d9a60?tpId=8&tqId=10999&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2012/12/08/1.6/))
            ([Leetcode Q48](https://leetcode-cn.com/problems/rotate-image))

	方法1: 两个for loop直接copy
	复杂度： O(n^2) space, O(n^2) time.
	
	方法2: inplace交换，两次翻转。先对角线交换，再垂直方向交换。注意左右/上下/主对角线/副对角线反转方法
	复杂度： O(1) space, O(n^2) time.

> 4.清除行列 ([CC150 Q7](https://www.nowcoder.com/practice/c95aac1506574dfc8ad44c3939c6739d?tpId=8&tqId=11000&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2012/12/09/1.7/))

	方法1: 用两个一维数组分别表示这一行/列是否出现过0.再扫描一遍只要判断该点的行列是否出现过0即可
	复杂度： O(n) space, O(n^2) time.

> 5.礼物的最大价值 ([剑指offer Q69](https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/))

    方法1: dfs。但是会超时因为有重复计算
	复杂度： O(n) space, O(mn) time.
	
	方法2: dp。使用原矩阵保存价值
	复杂度： O(1) space, O(mn) time.

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
sort(&str[0], &str[0]+str.length())	                         ## sort a string
reverse(str.begin(), str.end())                              ## reverse string
s1 == s2                                                     ## compare two string
char c[1000]; string s = c;                                  ## input string with char array. Useful for input
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
凡是字符串，可以考虑用 "unsigned int table[256]={0}" 或者vector<int> table(256, 0)) 来储存每个char的信息。

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

> 1.替代空格: " " -> "%20" ([剑指offer Q2](https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/))

	方法1: 扫描一遍计算空格个数，提前分配string，在扫描一遍双指针替换
	复杂度： O(n) time.
	
	方法2: python使用split(" ") 与 "%20".join()函数
	复杂度: O(n) time.

> 2.字符串的排列 ([剑指offer Q27](https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/)) ([CC150 Q44](https://www.nowcoder.com/practice/8380c8cf28954a188362206b1991b5d6?tpId=8&tqId=11038&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 先递归返回str[1:]的全排列，再将该数字插入每个全排列的不同位置，推入队列/数组，并将原来的全排列弹出
			最后需要通过hashtable去除重复的排列
	
	方法2: 递归。每一次将i>cur移到cur的位置做一次permutation。再swap回去
	
	方法3: 递归。每一次取其中的一位，将剩下的字符串premute之后，将该位放在开头
	
	方法4：使用dfs，用交换的方式保证某一位的开始。
	相似题型：全排列 ([Leet Q46](https://leetcode-cn.com/problems/permutations))
	        全排列ii ([Leet Q47](https://leetcode-cn.com/problems/permutations-ii))

> 3.第一个只出现一次的字符 ([剑指offer Q34](https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/))

	方法1: 使用hash table保存遍历结果，value为出现次数。再扫描一次字符串输出第一个value=1的字符
	复杂度： O(n) space, O(n) time.
	
	方法2: 因为字符个数有限，使用一个unsigned int table[256]保存每个char的出现个数。每个字符对应位置为int(str[i])。
	复杂度： O(n) space, O(n) time.

> 3.左旋转字符串 ([剑指offer Q43](https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 先反转[:n],再翻转[n:],最后整体翻转
	复杂度： O(1) space, O(n) time.
	相关问题：翻转单词顺序列。旋转链表（同样分别旋转两部分最后一起翻转）

> 4_1.把字符串转换成整数 ([剑指offer Q49](https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof)) ([Leetcode Q8](https://leetcode-cn.com/problems/string-to-integer-atoi)))

	方法1: 注意第一位为+/-，溢出，invalid char，“”的情况。
		   判断溢出即可以用long long表示值与MAX_INT对比，也可以再乘10前对比n与MAX_INT/10.
		   更好记住的退出条件是 if(res>INT_MAX/10 || ((res==INT_MAX/10) && str[move] > '7')) 则返回最大或最小
	复杂度： O(1) space, O(n) time.

> 5.正则表达式匹配 ([剑指offer Q52](https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/)) ([Leetcode Q10](https://leetcode-cn.com/problems/regular-expression-matching/))

	方法1: 递归判断。注意到字符串尾时=='\0'
			下一位不为'*'时，只有*str==*pattern或者*str!='\0'&&*pattern=='.'，将两个都向前一位递归判断match(str+1,pattern+1)
			下一位是‘*’时：
				同样的条件满足时，判断match(str+1,pattern)或match(str,pattern+2) --不match或者match一至多位
				不满足只判断match(str,pattern+2) -- 则没有match上该位
    复杂度： O(n) space, O(n) time.

> 6.表示数值的字符串 ([剑指offer Q53](https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/)) ([Leetcode Q65](https://leetcode-cn.com/problems/valid-number/))

	方法1: 分为e/E前后判断。后面的只能是整数。前面的最多只能有一个dot。注意边界检查条件。
	
	方法2：先去除两边的空号，然后遍历l到r，根据每个遇到的值判断
	      - 遇到数字，将showNum设置为真
	      - 遇到+-号，确保+-号在i的位置，或者s[k-1]=='e'或'E'
	      - 遇到'e'或'E'：确保只出现过一次（showE）而且数字曾经出现过，并且将showNum设置为false（为了后面必须仍然遍历），showE设置为true
	      - 遇到'.'：确保只出现过一次，而且e不曾出现过
	      最后返回showNum的值

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
	相似题目：回文子串([Leetcode Q647])
	
	方法2: Manacher算法 （to be understand, not implement yet）
	复杂度： O(1) space, O(n) time.

> 10.两个字符串是否同构 ([CC150 Q3](https://www.nowcoder.com/practice/164929d4acd04de5b0ee2d93047b3b20?tpId=8&tqId=10996&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2012/12/06/1.4/))
                     ([Leetcode Q242](https://leetcode-cn.com/problems/valid-anagram/))

	方法1: 对两个字符串先排序，在比较是否完全一样
	复杂度： O(1) space, O(nlogn) time.
	
	方法2: 用额外数组记录出现a中字符出现次数，再依次通过b的减去判断是否为0
	复杂度： O(n) space, O(n) time.

> 11.是否为旋转字符串 ([CC150 Q8](https://www.nowcoder.com/practice/bc12808a2b0f445c96a64406d5513e96?tpId=8&tqId=11001&rp=1&ru=%2Fta%2Fcracking-the-coding-interview&qru=%2Fta%2Fcracking-the-coding-interview%2Fquestion-ranking&tPage=1)) ([CC150 Sol](http://hawstein.com/2012/12/10/1.8/))

	方法1: 对s1每一个break point，检查后+前的组合是否为s2
	复杂度： O(1) space, O(n^2) time.
	
	方法2: 构造一个O(n)时间的子串检查函数，如果s2是s1+s1的子串，则s2为s1的旋转
	复杂度： O(n) space, O(n) time.
	相关问题：子串判断

> 12.最长合成字符串 ([CC150 Q76](https://www.nowcoder.com/practice/92a6faa7377f4c049a18154b24458d2a?tpId=8&tqId=11070&tPage=4&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2013/03/04/20.7/))

	方法1: 先将字符串组按照长度排序。从长的开始，判断该字符串是否可以被后面的字符串构成。
		  每次可将后面的字符串保存在map中确定是否出现。对该判断字符串，如果map出现return true，
		  否则依次递归判断构成该字符串的前后两个子串是否可以被构成

> 13.子串查找

	方法1: to be done

> 13_1.字符串多模式匹配 ([CC150 Q77](https://www.nowcoder.com/practice/917a800d4de1423394827932f4725c68?tpId=8&tqId=11071&tPage=4&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2013/03/05/20.8/))

	方法1: 对vector中每个子串，用s.find()判断其是否为一个子串
	
	方法2: 构造一个Trie树。将str所有的后缀插入树中。如果为子串，则必定在树中

> 14.最长无重复子串 ([Leetcode Q3](https://leetcode.cn/problems/longest-substring-without-repeating-characters/))

	方法1: 用一个前指针记录前一个当前最前面无重复的起始点。用一个map记录重复的情况。
	      默认初始最前无重复的前指针位置为-1. 更新的是滑动窗口的左窗，如果现在的在窗口中出现过，更新左窗位置
	      当map发现新的字符串重复过，更新前指针到上次重复位置的后一位。
	复杂度： O(n) space, O(n) time. O(1) space if using int[256]

> 15.反转单词顺序 ([剑指offer Q71](https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/)) ([Leetcode Q151](https://leetcode-cn.com/problems/reverse-words-in-a-string))

    方法1：先反转整个string，再反转每一个单词。先用双指针记录左右最早不为空的位置。然后用stack记录并更新每一个单词并反转。注意最后一个位置
    复杂度： O(n) space, O(n) time
    
> 16.括号生成 ([Leetcode Q22](https://leetcode-cn.com/problems/generate-parentheses/))

    方法1：dfs，用l/r记录当前剩余左右括号数。r==0输出，l==0补右括号，l==r补左括号，其余先补做再补右
    复杂度： O(n) space, O(n) time
    
> 17.字母异位词分组 ([Leetcode Q49](https://leetcode-cn.com/problems/group-anagrams/))

    方法1：异位词通过sort可以变成等价(O(nlogn)time, 通过dict判断次数可以到O(n)). 通过一个dict，用sort string当作k，value是对应的数组
    复杂度： O(nk) space, O(nklogk) time
    
> 17_2.找到所有的异位词 ([Leetcode Q438](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string))

    方法1：滑动窗口， 不断更新长度为26的数组中的count， 不断地判断是否满足所有的count都为0
    复杂度： O(26) space, O(m + (n-m) * 26) time
    
    方法1：滑动窗口，但是不需要每次更新完数组都计算数组是否全为0， 用一个diff变量比较即可。再每一次窗口变动的时候，需要根据进出值的情况维护
          数组和diff变量。但是每次窗口变动， 减少了比较需要的时间
    复杂度： O(26) space, O(n+m+ 26) time
    
> 18.最小覆盖子串 ([Leetcode Q76](https://leetcode-cn.com/problems/minimum-window-substring))

    方法1：用一个hash table c2保存目标子串的各位count。双指针滑动窗口遍历。另一个table c1记录实际遇到的情况
          当end指针遇到目标字串(c2[end]>0)时，在c1[end]记录下来。如果此时c1[end]<=c2[end], count++，此时窗口中成功数量+1.
          更新最小窗口的左界时，要不就是当前位置不在c2中，要不就是c1[start]>c2[start]，直到两个条件都不符合，得到最小窗口
    复杂度： O(n) space, O(n) time
    
> 19.字符串按频率排序 ([Leetcode Q451](https://leetcode-cn.com/problems/sort-characters-by-frequency))

    方法1：用map遍历记录每个char出现的次数，将<n, char> pair放到vector排序，按照大到小的顺序输出
    复杂度： O(n+k) space, O(n+klogk) time, k is different number of char
    
    方法2：用map遍历记录每个char出现的次数, 记录出现的最大频率，建立max_count+1大小的数组，把不同的char放进去桶排序
    复杂度： O(n+k) space, O(n+k) time
    相似题目：前K个高频数([Leetcode Q451])
    
> 20.字符串的排列 ([Leetcode Q567](https://leetcode-cn.com/problems/permutation-in-string/))

    方法1：滑动窗口。用map从s1统计出现的个数，滑动窗口目的是让m的所有值为零。
          每次右窗口移动，添加c，更新map的值(map[c]--)。如果map[c]<0, 说明这个c加多了，不断移动左窗口
          每一回合都能保证加入的数值c不会过多。如果窗口大小刚好等于s1大小，说明不多不少全占有了
    复杂度： O(k) space, O(n)
    相似题目：字符串中的所有异位词([Leetcode Q483])：只要把每次的l推入数组输出即可
    
> 21.最长公共前缀 ([Leetcode Q14](https://leetcode-cn.com/problems/longest-common-prefix/))

    方法1：n个数每次对比第i位
    复杂度： O(1) space, O(mn) time
    
    方法2：先将string排序，对比最前和最后的前缀即可
    复杂度： O(1) space, O(mnlogn) time
    
> 22.字符串相乘 ([Leetcode Q43](https://leetcode-cn.com/problems/multiply-strings/))

    方法1：num1每次乘num2从后开始的某一位，补上0，然后做字符串相加
    复杂度： O(1) space, O(mn) time
    
> 23.罗马数字和整数 ([Leetcode Q12](https://leetcode-cn.com/problems/integer-to-roman/)) ([Leetcode Q13](https://leetcode-cn.com/problems/roman-to-integer/))

    方法1：罗马数字转整数-用map记录下罗马数字到数字的转换。遍历罗马数字，当前面的罗马数字小于后面时，减掉此值。否则为加
          整数转罗马数字-直接记录下所有可行的罗马数字组合，从大到小排列，num-nums[i]，直到num==0
    
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
l.splice()
    l.splice(it, l2)                                        ## transfer whole l2 list to l's it pos
    l.splice(it, l2, it2)                                   ## transfer l2's it2 item to l's it pos
    l.splice(it, l2, it_start, it_end)                      ## transfer l2's it_start-it_end items to l's it pos
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
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def printList(l):
	res = []
	while l:
		res.append(l.val)
		l = l.next
	return res

def buildList(arr):
    f = ListNode()
    m = f
    for n in arr:
        m.next = ListNode(n)
        m = m.next
    return f.next
```

### 问题及思路

> 1.从尾到头返回链表的值 ([剑指offer Q3](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/))

	方法1: 反转链表再返回
	复杂度： O(1) space, O(n) time.
	
	方法2: 用额外的stack储存，再返回
	复杂度： O(n) space, O(n) time.

> 2.链表中倒数第k个结点 ([剑指offer Q14](https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof))

	方法1: 双指针，让头指针先走k步，再让前后指针一起走
	复杂度： O(1) space, O(n) time.
	相似题目：移除倒数第k个节点

> 3_1.反转链表 ([剑指offer Q15](https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof)) ([Leetcode Q206](https://leetcode-cn.com/problems/reverse-linked-list))

	方法1: 常规操作,与1相同
	复杂度： O(1) space, O(n) time.
	
> 3_2.两两一组反转链表 ([Leetcode Q24](https://leetcode-cn.com/problems/swap-nodes-in-pairs/))

	方法1: 构造一个dummy head，在线交换链表节点
	复杂度： O(1) space, O(n) time.
	
> 3_3.反转链表II ([Leetcode Q92](https://leetcode-cn.com/problems/reverse-linked-list-ii/))

	方法1: 构造一个dummy head，先走left步，在线调换剩下right-left步的链表
	复杂度： O(1) space, O(n) time.
	
> 3_4.K个一组反转链表 ([Leetcode Q25](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/))

	方法1: 3_3的加强版。先移动k-1次找到断点（如果期间已经到底了，直接返回），将head到断点反转（需要dummy）。然后将后续的递归调用。
	复杂度： O(1) space, O(n) time.
	
> 3_5.旋转链表 ([Leetcode Q61](https://leetcode-cn.com/problems/rotate-list/))

	方法1: 先走完链表，记录数量，同时把尾节点连到head。再走count - k%count-1步，断开即可
	复杂度： O(1) space, O(n) time.

> 4_1.合并两个排序链表 ([剑指offer Q16](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)) ([Leetcode Q21](https://leetcode-cn.com/problems/merge-two-sorted-lists/))

	方法1: 递归。若有一个指针为空，返回另一个指针，否则指向数值较小的指针，并移动该指针头，递归得到
	复杂度： O(1) space, O(n) time.
	
> 4_2.合并K个排序链表 ([Leetcode Q23](https://leetcode-cn.com/problems/merge-k-sorted-lists))

    方法1: 每次找到最小的那个，把head向后移动，然后递归
	复杂度： O(1) space, O(nk) time.
	
	方法2: 两个两个合并，类似二分
	复杂度： O(1) space, O(nlogk) time.
	
	方法3: 用一个priority queue保存队列头。每次推出最小的那个，并把他的next推进去
	复杂度： O(k) space, O(nlogk) time.

> 5.复杂链表的复制 ([剑指offer Q25](https://leetcode-cn.com/problems/fu-za-lian-biao-de-fu-zhi-lcof)) ([Leetcode Q138](https://leetcode-cn.com/problems/copy-list-with-random-pointer/))

	方法1: 先复制所有的next节点，并用map保存两个链表1on1的对应。然后复制random指针，通过map找到对应的值
	复杂度： O(n) space, O(n) time.
	
	方法2: 现在同一个链表中每个节点后面添加一个复制节点。在扫描一次将后面的复印节点random指针指向对应的复制节点
	复杂度： O(1) space, O(n) time.

> 6.两个链表的第一个公共结点 ([剑指offer Q36](https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/)) ([Leetcode Q160](https://leetcode-cn.com/problems/intersection-of-two-linked-lists))

	方法1: 使用一个map保存链表1的结果。链表2扫描找到第一个在map中的数
	复杂度： O(n) space, O(n+m) time.
	
	方法2: 计算两个链表的长度，找到长度差d。长链表先走d步，两个再一起走知道相等
	复杂度： O(1) space, O(n+m) time.
	
	方法3： 交叉遍历. 一个到底了去遍历另一个。如果不相交，总有一个为null
	复杂度： O(1) space, O(n+m) time.

> 7.圆圈中最后剩下的数(约瑟夫环问题) ([剑指offer Q46](https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/))

	方法1: 从数组构建链表，然后loop返回
	复杂度： O(n) space, O(mn) time.
	
	方法2: 归纳法。推出f(n,m) = (f(n-1,m)+m)%n。f(1,m)=0. 再dp求得。如果起点为1则+1。动态归纳问题
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

> 9_1.删除排序链表中重复的结点 ([Leetcode Q83](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/))

	方法1: 递归判断是否遇到重复节点。是的话跳过这一段。注意下一节点为null的情况。
	复杂度： O(1) space, O(n) time.

> 9_2.删除未排序链表中重复的结点 ([CC150 Sol](http://hawstein.com/2012/12/13/2.1/))

	方法1: 双指针，每次遇到一个，删除后面所有相同的。
	复杂度： O(1) space, O(n^2) time.
	
	方法2: 用一个hash判断该节点是否曾经出现过
	复杂度： O(n) space, O(n) time.

> 10_1.删除链表节点 ([剑指offer Q18](https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/)) ([CC150 Sol](http://hawstein.com/2012/12/15/2.3/))
                
	方法1: 将指向节点的下一个节点的值copy至指向节点。再删除下一个节点
			如果该节点是尾节点，则必须要遍历
	复杂度： O(1) space, O(1) time. O(n) for ending node

> 10_2.删除链表值为val的节点 ([Leetcode Q203](https://leetcode-cn.com/problems/remove-linked-list-elements))
                
	方法1: 递归，head->next = removeVal(head->next)，如果自身等于val直接返回head->next
	复杂度： O(n) space, O(n) time

> 11.分割链表 ([CC150 Q10](https://www.nowcoder.com/practice/0e27e0b064de4eacac178676ef9c9d70?tpId=8&tqId=11004&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))
             ([Leetcode Q86](https://leetcode-cn.com/problems/partition-list/))

	方法1: 使用大小两个链表进行添加。注意大链表最后next要指向null.
	复杂度： O(1) space, O(n) time.

> 12.链表相加 ([CC150 Q11](https://www.nowcoder.com/practice/ed85a09f0df047119e94fb3e5569855a?tpId=8&tqId=11005&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2012/12/16/2.4/)) ([LeetCode Q2](https://leetcode.com/problems/add-two-numbers/))

	方法1: 注意对while条件的判断，只要(a || b || carry)即可继续，赋值可用a?a->val:0进行。减少过多代码
	复杂度： O(1) space, O(n) time.

> 13.回文链表 ([Leetcode Q243](https://leetcode-cn.com/problems/palindrome-linked-list/)) ([CC150 Q12](https://www.nowcoder.com/practice/baefd05def524a92bcfa6e1f113ed4f0?tpId=8&tqId=11006&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 使用一个stack，全部推入判断堆顶是否一次相等
	复杂度： O(n) space, O(n) time.
	
	方法2: 使用一个stack和快慢指针，将慢指针经历的推入堆中，在慢指针一次遍历比较stack顶。注意长度为奇偶时的区别
	复杂度： O(n) space, O(n) time.
	
	方法3： 用快慢指针，并将后续的反转。依次判断。注意奇偶情况。按照长度，要在头上加一个dummy node
	复杂度： O(1) space, O(n) time.
	
> 14.排序链表 ([Leetcode Q148](https://leetcode-cn.com/problems/sort-list/))
	
	方法1： 用快慢指针，并用prev记录慢指针上一个位置。fast到底时断开prev和后面的，sort(head, slow）两部分，然后mergeSortedList
	复杂度： O(logn) space, O(nlogn) time.
	
> 15.LRU机制 ([Leetcode Q146](https://leetcode-cn.com/problems/lru-cache/submissions/))
	
	方法1： 用一个list（双向链表）保存最近access列表，用一个map<int, list<CacheNode>::iterator>保存 key到链表位置的dict
	       get：map中查找的到，将map对应到的it用splice更新到list头，输出他的值；找不到输出-1
	       put：map中查找的到：
	                将map对应的it用splice更新到list头，更新其value
	            map中查找不到：
	                如果list到达capicity长度，pop掉最后一个，将对应的key从dict中删。然后在list头上加上node，并且用dict记录
	复杂度： O(n) space, O(1) time（用双向链表list，要自己实现就算了）.
	
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
 *     TreeNode(int x): val(x), left(NULL), right(NULL) {}
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

> 1.从前序遍历与中序遍历结果重建二叉树 ([剑指offer Q4](https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/)) ([Leetcode Q105](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/))

	方法1: 前序遍历数组[根结点，左子树节点，右子树节点] && 中序遍历数组[左子树节点，根结点，右子树节点]
		于是通过前序的第一个root，将中序分隔开来，递归重建左右子树

> 2.树的子结构 ([剑指offer Q17](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof))

	方法1: 递归。如果root1==root2，递归判断左右子树是否完全相等；若不是，递归判断root1的左右子树是否是包含root2子树

> 3.二叉树的镜像 ([剑指offer Q18](https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/)) ([Leetcode Q226](https://leetcode-cn.com/problems/invert-binary-tree/))

	方法1: 递归。互换左右子树，再递归完成子树的替换
	复杂度： O(1) space, O(n) time.
	
	方法2: 使用queue，每次互换最头上的节点的左右子树，再将左右子树的节点推入队列
	复杂度： O(n) space, O(n) time.

> 4.从上往下打印二叉树（层级遍历）([剑指offer Q22](https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/))

	方法1: 使用queue，每次弹出队列的头，将左右子树推入队尾
	复杂度： O(n) space, O(n) time.
	相关问题：- 把二叉树打印成多行（每次要记录queue的大小，每次pop掉一层的节点）
			- 将某一层输出成为链表 (CC150 Q20)

> 5.二叉搜索树的后序遍历序列构造二叉树 ([剑指offer Q23](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof))

	方法1: 后序遍历数组[左子树节点，右子树节点，根结点]。注意这是二叉搜索树
          每次通过根节点找到数组前面第一个比根节点大的数作为右子树开始（找不到则返回自己的位置）。
          判断断开的右子树是否全部比根节点大
          再递归判断左右子树是否为二叉搜索树

> 6_1.路径总和（[Leetcode Q112](https://leetcode-cn.com/problems/path-sum/))

	方法1: 递归. 为叶子节点就判断是否值为target。否则递归左右子树是否含有路径
	复杂度：O(n) space, O(n) time
	
> 6_2.二叉树中和为某一值的路径 ([剑指offer Q24](https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/)) ([Leetcode Q113](https://leetcode-cn.com/problems/path-sum-ii/))

	方法1: 递归。每次查找左右子树值为target-root的路径，存在则将自己推入路径。只有叶节点能直接放回路径。
	
	方法2： dfs。用一个global保存。是前序便利的方法，每次走通一条子树
	
> 6_3.root到叶子节点之和 ([Leetcode Q129](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/))

	方法1: 递归. 要加入prevsum，为叶子节点输出prevsum*10 + root->val, 否则左右子树相加
	复杂度：O(n) space, O(n) time
	
> 6_4.最大路径和 ([Leetcode Q124](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/))

	方法1: 递归. 由于路径不一定要到叶子节点，可以左右子树相连。最大和递归计算时可以把左右都加进来，但是输出给上一层时只能取左右最大的一支
	复杂度：O(n) space, O(n) time
	
> 6_5.不一定从根节点开始的路径总数 ([Leetcode Q437](https://leetcode-cn.com/problems/path-sum-iii/))

	方法1: 前缀和记录到节点某个父节点的和，到本节点时，查找new_sum - target是否在dict中。注意sum和dict在dfs之后都要回溯
	复杂度：O(n) space, O(n) time
	
> 6_6.二叉树的最长路径 ([Leetcode Q543](https://leetcode.com/problems/diameter-of-binary-tree))

	方法1: dfs函数记录从root开始的最大深度。用一个global记录max(l+r+1)为最大路径（左+右最大深度+1）。和6_4十分接近
	复杂度： O(1) space, O(n) time

> 7.二叉搜索树与双向链表 ([剑指offer Q26](https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&tqId=11179&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 递归。用一个自定义的TopEndNode保存左右子树恢复的双向链表的头尾。再与root节点融合成新的双向链表
	struct TopEndNode {
	    struct TreeNode* top;
	    struct TreeNode* end;
	    TopEndNode(): top(NULL), end(NULL) {}
	};
	
	方法2： dfs。要用全局变量。dfs进行中序遍历，最先获取左下角最小的设为head。后面用cur和pre持续更新连接。
	
> 8_1.二叉树的深度 ([剑指offer Q38](https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof))

	方法1: 递归。叶节点返回深度为1.根节点返回1+max(左深度，右深度）
	
	方法2: dfs修改depth并回溯。记录max depth
	
> 8_2.二叉树的最小深度 ([Leetcode Q111](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/))

	方法1: 递归。判断时注意子树为0的情况，这种情况下不能用1+min(l,r)只能l+r+1

> 9.平衡二叉树判断 ([剑指offer Q39](https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/)) ([CC150 Q17](https://www.nowcoder.com/practice/b6bbed48cd864cf09a34a6ca14a3976f?tpId=8&tqId=11011&rp=1&ru=%2Fta%2Fcracking-the-coding-interview&qru=%2Fta%2Fcracking-the-coding-interview%2Fquestion-ranking&tPage=1)) ([CC150 Sol](http://hawstein.com/2012/12/24/4.1/))
                 ([Leetcode Q110](https://leetcode-cn.com/problems/balanced-binary-tree/))

	方法1: 递归求出左右子树的深度。如果深度相差不超过1则为平衡树。递归判断左右子树
	
	方法2: 方法1需要重复访问节点。于是从叶节点记录depth的深度并递归返回到根节点，相当于dp。
	       int depth = 0;
	       return IsBalanced(pRoot, &depth);

> 10.二叉搜索树中两个节点的最低公共祖先 ([剑指offer Q72](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/))  ([Leetcode Q235](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/))

	- 若为二叉搜索树，假设两个节点的值分别为min_v, max_v, 则可以从root找到第一个min_v < node < max_v的节点。若node等于其中某个值，则其中一个节点为另一节点的子孙
	- 否则一左一右时即为该节点

> 10_1.二叉树中两个节点的最低公共祖先 ([剑指offer Q73](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/))  ([Leetcode Q236](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/))

	方法1：若都不满足（不一定为二叉树，不是搜索树，没有指向父节点的指针），则先从root找到到达两个节点的path（递归+深搜），然后比较两个path，求出两条路径的最后公共节点

    方法2：递归。左右分别调用。如果左右结果都为空，证明当前节点就是祖先。否则就为左右不为空的调用。
          结束方式就是如果root为空或者root为左或右的某个。
    
> 10_2.满二叉树的最低公共祖先 ([CC150 Q23](https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&tqId=11017&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 注意到每个节点的父亲编号都是自己的一半。用两个stack保存路径，查看最后相同的堆顶值
	复杂度： O(n) space, O(n) time.
	
	方法2: 直接比较两个编号。若不相等，大的数除以2，直到相等。
	复杂度： O(1) space, O(n) time.

> 11.二叉树的下一个结点 ([剑指offer Q57](https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 多种情况判断
			- node为空时，返回NULL
			- node右子树存在时，返回右子树最左下的叶节点
			- node不为root时，找到第一个 节点是-父节点的左节点的-父节点。
				即 if (pNode->next->left==pNode)
	            	return pNode->next;
	
	方法2: 直接中序遍历

> 11_1.二叉树的下一个结点(不存在父节点) ([CC150 Q22](https://www.nowcoder.com/practice/60231d6931d543d4aadcb67851b21e4a?tpId=8&tqId=11016&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2012/12/28/4.5/))

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

> 12.对称的二叉树 ([剑指offer Q58](https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof)) ([Leetcode Q101](https://leetcode-cn.com/problems/symmetric-tree/))

	方法1: 求出pRoot的镜像树pRoot_mirror,对比两个树是否完全一致
	复杂度： O(n) space, O(n) time, and need repeative visit.
	
	方法2: 对比root的两个子树是否对称，可递归判断(left->right,right->left) && (left->left,right->right) 是否都对称
	复杂度： O(1) space, O(n) time.

> 13.按之字形顺序打印二叉树 ([剑指offer Q59](https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 用两个stack记录每层结果，用一个bool记录是向左还是向右遍历。
		  每次将一个stack中的子节点向另一个方向传输。通过方向确定先传左还是先传右
	复杂度： O(n) space, O(n) time

> 14.序列化二叉树 ([剑指offer Q61](https://leetcode-cn.com/problems/xu-lie-hua-er-cha-shu-lcof/)) ([Leetcode Q297](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/))

	方法1: 用queue进行层级遍历，用#表示null，用空格隔开不同节点。
	复杂度： O(n) space, O(n) time
	
	方法2：使用istringstream与ostringstream进行前序遍历。注意两个的使用
	复杂度： O(n) space, O(n) time

> 15.二叉树的中序遍历 ([Leetcode Q94](https://leetcode.com/problems/binary-tree-inorder-traversal/))

	方法1: 递归。传入一个可修改的vector，左子树先调用，root推入值，右子树在调用。
	复杂度： O(1) space, O(n) time
	
	方法2: 使用stack。p不为空时，推入自己，p指向p->left。p为空时，p=stack.top()，将p的值推入结果vector，stack pop()，再让p指向p->right
	复杂度： O(n) space, O(n) time
	
	方法3: dfs
	复杂度： O(1) space, O(n) time

> 16_1.二叉树搜索树的第k个节点 ([Leetcode Q230](https://leetcode.com/problems/kth-smallest-element-in-a-bst/))

	方法1: 递归。先用一个函数递归求树的节点数目。如果左节点数目等于k-1，返回root；大于k-1则返回左子树的第k个；否则返回右子树的k-leftcount-1个节点
	复杂度： O(1) space, O(n) time，但是多次递归开销很大
	
	方法2: 先用15的方法1求出vector，在返回vector的第k-1个数
	复杂度： O(n) space, O(n) time，但是多次递归开销很大
	
	方法3: 使用15的方法2的stack，在推入的时候改为记录count，返回第k个count的时候的值
	复杂度： O(n) space, O(n) time
	
	方法4: dfs从左节点->根节点->右节点遍历，记录下第k个值
	复杂度： O(n) space, O(n) time

> 16_2.二叉搜索树第K大的节点 ([剑指offer Q70](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/))

    方法1: 从右中序遍历就是排序。用一个global值记录即可即可
	复杂度： O(1) space, O(n) time

> 17.递增数列构建最低二叉搜索树 ([CC150 Q19](https://www.nowcoder.com/practice/01a12f94988649e39b554d95c45bfa6f?tpId=8&tqId=11013&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2012/12/26/4.3/))

	方法1: 每次取mid，递归构建

> 18.判断二叉搜索树 ([CC150 Q21](https://www.nowcoder.com/practice/536c0199151245f897da2c5390930657?tpId=8&tqId=11015&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))
                  ([Leetcode Q98](https://leetcode-cn.com/problems/validate-binary-search-tree))

	方法1: dfs. 判断pre的结果是不是比cur小或等。最开始的时候pre为NULL
	复杂度： O(n) space, O(n) time

> 19.维护数组的rank ([CC150 Q58](https://www.nowcoder.com/practice/0ade0d95c85349beb934a90b1d9b02be?tpId=8&tqId=11052&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 暴力检查
	复杂度： O(1) space, O(n^2) time
	
	方法2: 用二叉搜索树保存stream的结果，每次查找rank。
	复杂度： O(n) space, O(logn) time

> 20.二叉树第二小的节点 ([Leetcode Q671](https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/))

    方法1: dfs查找刚好比root大的点，要注意初始输入的res大小
	复杂度： O(n) space, O(n) time
	
> 21.二叉搜索树的众数 ([Leetcode Q501](https://leetcode-cn.com/problems/find-mode-in-binary-search-tree))

	方法1: dfs. 用last val记录上一个遍历的数，用pre初始化。每次判断和上一个数是不是一样的，更新count和max count。
	      当count == maxcount时，一定是新的众数来了，推入res。如果大于，证明唯一的新的众数来了，清空res并且推入新的众数
	复杂度： O(n) space, O(n) time
	
> 22.Trie树 ([Leetcode Q208](https://leetcode-cn.com/problems/implement-trie-prefix-tree/))

	方法1: struct TrieNode{
                bool isEnd;
                struct TrieNode* ptr[26];
                TrieNode(bool e): isEnd(e) {
                    memset(ptr, 0, sizeof(ptr));
                }
            };
            用此结构记录每一个节点，isEnd用于记录此节点是否为终点。Root为一个isEnd为true的节点
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

> 1_1.两个栈实现队列 ([剑指offer Q5](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)) ([Leetcode Q232](https://leetcode-cn.com/problems/implement-queue-using-stacks/))

	方法1: 往stack1中push; pop时如果stack2为空，先将stack1从顶pop过来，然后返回stack2的top，不为空则直接返回
	复杂度： O(n) space, O(1) time.

> 1_2.队列实现栈 ([Leetcode Q225](https://leetcode-cn.com/problems/implement-stack-using-queues/))

	方法1: 两个队列，每次push的时候先把q1的推到q2，然后推入q1。最后q2推回来
	复杂度： O(n) space, O(n) time for push/O(1) time for pop.
	
	方法2: 一个队列，可以把先推进来的推到后面去
	复杂度： O(n) space, O(n) time for push/O(1) time for pop.

> 2.包含min函数的栈 ([剑指offer Q20](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)) ([Leetcode Q155](https://leetcode-cn.com/problems/min-stack/))

	方法1: 用一个额外的栈保存至今最小的数，与value栈同步。若新加的数更小，推入新数，否则推入栈顶的数(事实上额外的栈不需要保存重复的最小值，如果新的值不大于栈顶的值则推入；如果pop的值==栈顶值一同pop掉)
	复杂度： O(n) space, O(1) time for min().

> 3.栈的压入、弹出序列 ([剑指offer Q21](https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/)) ([Leetcode Q946](https://leetcode-cn.com/problems/validate-stack-sequences/))

	方法1: 用一个额外的栈按照压入的顺序不断推入，但当该栈顶的数等于弹出序列的头，弹出栈顶数与弹出序列的头（或移动index）
	复杂度： O(n) space, O(n) time.

> 4.双栈排序 ([CC150 Q15](https://www.nowcoder.com/practice/d0d0cddc1489476da6b782a6301e7dec?tpId=8&tqId=11009&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2012/12/23/3.6/))

	方法1: Insertion sort的方法，每次把栈顶插到temp栈对应的地方，temp栈顶大的数先push回原来的栈即可
	复杂度： O(n) space, O(n^2) time.

> 5_1.合法括号 ([CC150 Q45](https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&tqId=11039&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2013/01/12/8.5/))
              ([Leetcode Q20](https://leetcode-cn.com/problems/valid-parentheses))

	方法1: 使用一个stack，当栈顶为'('且A字符为')'弹出栈顶，否则一次输入A的字符。如果合法，stack应为空。
	复杂度： O(n) space, O(n) time.

> 5_2.最长有效括号 ([Leetcode Q32](https://leetcode-cn.com/problems/longest-valid-parentheses))

    方法1: 用stack。如果遇'('就把i推入，如果遇到')'就推出顶端，如果空了就把i推入；不空的话就计算现在到顶端的长度。一开始要推入-1
    复杂度： O(n) space, O(n) time
	
> 6_1.最大矩形 ([Leetcode Q84](https://leetcode-cn.com/problems/largest-rectangle-in-histogram))
	
    方法1: 固定每个i位置的高度h，双指针向左右延申知道无法增高。
	复杂度： O(1) space, O(n^2) time.
	
	方法2: 单调递增栈。单调递增栈可以找到一直向左、右最后一个比自己大的数（也就是矩形的允许最大的左边界、右边界）
	             只用一次的话，入栈操作标志了左边界，出栈的时候则标志了右边界。
	复杂度： O(1) space, O(n) time.
	
> 6_2.矩阵中的最大矩形 ([Leetcode Q85](https://leetcode-cn.com/problems/maximal-rectangle))
		
	方法1: 对每一行，可以看作上面的矩阵就是6_1中的矩阵。对每一行调用一次单调栈算法即可。
		   注意对输入height的更新，当matrix[i][j]！=1时，height被设置为0，否则为height上一轮的结果+1.
	复杂度： O(m) space, O(mn) time.
    
> 7.接雨水 ([Leetcode Q42](https://leetcode-cn.com/problems/trapping-rain-water))

    方法1: 某个点的雨水量为左右两边（包含自己）高度的最大值中的最小值 - 自身高度。用两个vector分别记录两边的最大值即可
    复杂度： O(n) space, O(n) time
    
    方法2: 单调递减栈
    复杂度： O(n) space, O(n) time
    
> 8_1.下一个最大数 ([Leetcode Q496](https://leetcode-cn.com/problems/next-greater-element-i/))

    方法1: 用一个单调栈持续记录右边的第一个更大的值，用dict保存
    复杂度： O(n) space, O(n) time
    相似题目：每日温度([Leetcode Q739]）
    
> 8_2.下一个最大数II ([Leetcode Q503](https://leetcode-cn.com/problems/next-greater-element-ii/))

    方法1: 同样使用单调栈。但是因为可以回到头上，需要重复遍历数组一次(i<2n-1)，对比保存的时候index都要 %
    复杂度： O(n) space, O(n) time

    
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

> 1.滑动窗口的最大值 ([剑指offer Q64](https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/))

	方法1: 暴力搜索每个slidingwindow。可以用dp思想稍微减少一点对比
	复杂度： O(1) space, O(nk) time.
	
	方法2: 使用一个动态维护的deque来构建每个窗口的slidingwindow。保证deque的头部永远是该windows内的最大值
		  每次加入的新的数之前，需要从尾部删除比新加的小的数。
		  然后从头删除已经不在slidingwindow内的数（所以deque存index而不存数字）
		  最后输出头部的数当作该窗口结果. 注意要当i>=k-1时才开始输出
	复杂度： O(k) space, O(n) time.
	
> 2.队列的最大值 ([剑指offer Q76](https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/))

    方法1: 要记录每个状态下的最大值，通过一个双边队列进行
	复杂度： O(1) space, O(n) time.
	
---
<br />

# <h2 id="8">堆（Heap)</h2>
### C++用法
```c++
-- (operation on vector) --
make_heap(vec.begin(), vec.end())                           ## make the heap to be the max heap. 'greater<int>()' as last argument turn it to min heap.
vec.front()                                                 ## get the first val(max) from max heap
vec.push_back(40); push_heap(vec.begin(), vec.end())        ## push a value. O(logn) time.
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

> 1.最小的K个数 ([剑指offer Q29](https://leetcode-cn.com/problems/zui-xiao-de-kge-shu-lcof/))

	方法1: 使用最小堆。构建堆，再推出直到第k个数
	复杂度： O(n) space, O(n+klogn) time. 当n>>k时效率高

> 2.数据流中的中位数 ([剑指offer Q63](https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/)) ([Leetcode Q295](https://leetcode-cn.com/problems/find-median-from-data-stream/))

	方法1: 内置vector，每次insert都保证sorted(插入排序)。
	复杂度： O(n) space, O(n) time for insertion. O(1) for getMedian
	
	方法2: 采用min heap + max heap. 保证min heap的数都比max heap大。且max heap的数总比min heap多。记录目前的count
			若现在count为偶数，插入是先进min heap，得到的min heap最小值释放并推入max heap。
			若现在count为奇数，插入是先进max heap，得到的max heap最大值释放并推入min heap。
			奇数的median返回max heap的最大，偶数的median返回min heap和max heap顶的平均值
		
		  更简单的实现是：先推入max，把max top推入min。如果长度不相等（一定是min多），把min的top推入max中
		               返回时判断大小，一样大返回两个top均值；max大返回max
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

> 1.矩阵中的路径 ([剑指offer Q65](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)) ([Leetcode Q79](https://leetcode-cn.com/problems/word-search/))

	方法1: 深搜，注意visit的表需要修改。注意传入函数的方式(dfs(int *&visit...))
	复杂度： O(n) space, O(n) time.

> 2.机器人的运动范围 ([剑指offer Q66](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/))

	方法1: 深搜. 判断时多加了条件而已。
	复杂度： O(n) space, O(n) time.

> 3.检查路径 ([CC150 Q18](https://www.nowcoder.com/practice/1b83885969f14329bf9222c1c54469a7?tpId=8&tqId=11012&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2012/12/25/4.2/))

	方法1: 深搜. 退出时可不将visit改为0，因为为有向图，不能到达则无需再次访问
	复杂度： O(n) space, O(n) time.
	
	方法2: 广搜. 用queue来实现
	复杂度： O(n) space, O(n) time.

> 4.N皇后问题 ([CC150 Q48](https://www.nowcoder.com/practice/8b5d63163fbe48719f2dfe01fe9f7e54?tpId=8&tqId=11042&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2013/01/15/8.8/))
             ([Leetcode Q51](https://leetcode-cn.com/problems/n-queens/))

	方法1: 简单dfs+回溯。每次添加一行，判断此时在每一列添加Q的时候，是否满足条件（之前的每一列都没有Q，右上、左上斜线都没有Q）
	      主要难在注意每一行推入的string为....Q...形式；以及左上右上遍历时的ij for loop

> 5.迷宫 ([CC150 Q46](https://www.nowcoder.com/practice/365493766c514d0da0cd774d3d40fd49?tpId=8&tqId=11040&rp=3&ru=%2Fta%2Fcracking-the-coding-interview&qru=%2Fta%2Fcracking-the-coding-interview%2Fquestion-ranking&tPage=3))

	方法1: bfs. 将输入的map直接当作visit table。queue每次push一个pos(x*m+y)，向四个方向进行查找。map直接保存到达该格的步数

> 6.字符串变换最短路径 ([CC150 Q79](https://www.nowcoder.com/practice/4818ae796bbc4a85a8cdd8e155c06d46?tpId=8&tqId=11073&tPage=4&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking))

	方法1: 使用bfs。相邻的定义即为两个字符串相差为1。用visit表示访问的距离。
		   queue保存遍历的字符串，用一个map将字符串和idx对应起来。主要注意开始时的字符串没有idx。

> 7.岛屿个数 ([Leetcode Q200](https://leetcode.com/problems/number-of-islands))

    方法1: 使用dfs。可注意的是不需要添加visit table，而直接使用map修改其值即可
    相关问题：最大岛屿面积 (Leetcode Q695)：每次dfs传入一个area的参数，在一个dfs中不断增加其值即可
    复杂度: O(1) space, O(mn) time.

> 8.课程表II ([Leetcode Q210](https://leetcode-cn.com/problems/course-schedule-ii/))

    方法1: 通过关系构建出邻接链表。通过dfs进行邻接链表和visit遍历，当无环时，可以成功拓扑排序
    复杂度: O(m+n) space and time.

> 9.解数独 ([Leetcode Q37](https://leetcode-cn.com/problems/sudoku-solver))

    方法1: dfs二维数组，当每一个空的位置，尝试往里加1-9的数组，dfs判断剩余的数组是否满足条件。
          注意判断新加的时候，可以判断已存在的数是否与当前冲突。如果冲突就不需要加进去了
    
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

> 1_1.二进制中的1的个数 ([剑指offer Q11](https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/))

	方法1: for loop 查看每一位的是否为1
	复杂度： O(1) space, O(1) time.
	
> 1_2.0到n中每个数1的个数 ([Leetcode Q338](https://leetcode-cn.com/problems/counting-bits))

	方法1: for loop 查看每一位的是否为1
	复杂度： O(1) space, O(n*32) time.
	
	方法2: 对于每个i来说，如果i为奇数，则i中1的个数比i-1中多一个；如果i为偶数，则与i/2中个数一样。dp即可
	复杂度： O(1) space, O(n) time.
	
> 2_1.2的幂 ([Leetcode Q231](https://leetcode-cn.com/problems/power-of-two/))

	方法1: for loop 查看每一位，记下count数量
	复杂度： O(1) space, O(1) time.
	
	方法2: n&(n-1) == 0. 任何一个1000 - 1都是0111的形式，&一定为0
	复杂度： O(1) space, O(1) time.

> 2_2.数组中只出现一次的两个数字 ([剑指offer Q40](https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/))

	方法1: 使用map记录每个数字出现的个数
	复杂度： O(n) space, O(n) time.
	
	方法1: 使用xor（a xor a = 0）. 将所有数字xor一遍。找到结果中不为0的一位，则两个数字在这一位必不同
			按照该位将数字分为两组。分别进行xor并输出两个结果
	复杂度： O(1) space, O(n) time.
	相关问题：只出现一次的三个数字(每一位求1的个数和，如果余3为1证明唯一的数这里是1。可拓展到其他情况)

> 3.最接近的数 ([CC150 Q27](https://www.nowcoder.com/practice/33ad4d168a3247b9b63f41e4eaded652?tpId=8&tqId=11021&rp=1&ru=%2Fta%2Fcracking-the-coding-interview&qru=%2Fta%2Fcracking-the-coding-interview%2Fquestion-ranking&tPage=2)) ([CC150 Sol](http://hawstein.com/2013/01/04/5.3/))

	方法1: 对于0001100，更大的一个数是另左边第二次出现连续的0时成为1,后面补0->0010000
		再将后面多加不足的1->0010001. 整个过程为x + 1<<c_0 + 1<<(c_01-1) - 1,c_0=2,c_01=2
		对于1100011，更小的一个数是另左边第二次出现连续的1时成为0，后面补1->1011111
		再将后面多余的1变成0->1011100. 整个过程为x - (1<<c_1) - 1<<(c_10-1) + 1, c_1=2,c_10=3

> 4.交换奇偶数位 ([CC150 Q29](https://www.nowcoder.com/practice/ed7d014b42e740679c4bd69b9d9c49b9?tpId=8&tqId=11023&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2013/01/04/5.6/))

	方法1: 用mask表示奇数与偶数(0x55555555, 0xAAAAAAAA). 输出(odd<<1 | even>>1)

> 5_1.集合的子集 ([CC150 Q43](https://www.nowcoder.com/practice/1f2700e2b1904254b55765479e9b8766?tpId=8&tqId=11037&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2013/01/10/8.3/))
               ([Leetcode Q78](https://leetcode-cn.com/problems/subsets))

	方法1: 一个集合的全排列可以用n个1表示，则最大为2^n-1, 最小为1(非空子集)。按照位置加入元素即可。但是这个必须要数组小于32才可以用
	复杂度： O(1) space, O(2^n) time.
	
	方法2: dfs。添不添加自己都做一次dfs。
	复杂度： O(2^n) space, O(2^n) time.
	
> 5_2.集合数量为k的子集 ([Leetcode Q77](https://leetcode-cn.com/problems/combinations))
    
    方法1: 一个集合的全排列可以用n个1表示，则最大为2^n-1, 最小为1(非空子集)。当1的个数为k时加入
	复杂度： O(1) space, O(2^n) time.
	
	方法2: dfs。需要用两个start+cur保存现在的位置和当前的个数
	复杂度： O(2^n) space, O(2^n) time.

> 6_1.组合总数(有重复元素，但是不可重复挑选) ([Leetcode Q40](https://leetcode-cn.com/problems/combination-sum-ii/))

    方法1: 用(0,2^n-1)中每一个位置为1表示是否取元素组中的数，判断当前和是否为target。但是这个必须要数组小于32才可以用
	复杂度： O(1) space, O(2^n) time.
	
	方法2: dfs+剪枝。dfs从下一轮开始，但是注意因为有重复元素，需要先将数组排序，当当前item不等于上一个item时才挑选，不然有重复
	复杂度： O(n_target) space, O(n*2^n) time. 事实上比较难有确定界限
	
> 6_2.组合总数(无重复元素，但是可重复挑选) ([Leetcode Q39](https://leetcode-cn.com/problems/combination-sum/))

    方法1: dfs+剪枝。注意退出的时候要判断sum和target大小，dfs下一轮也可以从自身开始
	复杂度： O(n_target) space, O(n*2^n) time. 事实上比较难有确定界限
	
> 7.格雷编码 ([Leetcode Q89](https://leetcode-cn.com/problems/gray-code/))

    方法1: 对每个i，编码为i^(i>>1), 一共1<<N个数
	复杂度： O(1) space, O(2^n) time.
	
> 8.最大单词长度乘积 ([Leetcode Q318](https://leetcode-cn.com/problems/maximum-product-of-word-lengths/submissions/))

    方法1: 将每个单词使用bit编码成一个int， 查看是否有重复只需要用&即可
	复杂度： O(L+n^2) space, O(2^n) time.
	
	方法2：编码成int之后， 只需要用map储存最大的单词长度即可
	复杂度：  O(L+n^2) space, O(2^n) time.

---
<br />

# <h2 id="12">动态规划（Dynamic Programming）</h2>
### 问题及思路

> 1.斐波拉契数列 ([剑指offer Q7](https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: for loop 动态计算后面的值，注意溢出，long long保存结果
	复杂度： O(1) space, O(n) time.
	相关： 青蛙跳， 矩形覆盖

> 2.连续子数组的最大和 ([剑指offer Q30](https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/)) ([Leetcode 53](https://leetcode-cn.com/problems/maximum-subarray/))

	方法1: 使用一个额外的sum保存到该数的最大sum。如果sum为负则定义改出的sum为自身（最大sum必然不包括前面的负数和）
	复杂度： O(1) space, O(n) time.
	相关问题：最大和子矩阵[CC150 Q81]: 每次将i～j行加起来，求连续字数组最大和。O(n)space，O(n^3) time.

> 3.连续子数组的最大积 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/05.01.html)) ([Leetcode Q152](https://leetcode-cn.com/problems/maximum-product-subarray/))

	方法1: 由于有负数的存在，同时需要保存有负数的情况。
			状态转移: max[i] = max(max[i-1]*A[i], min[i-1]*A[i], A[i]) -> 结果在此数组中更新
					 min[i] = min(max[i-1]*A[i], min[i-1]*A[i], A[i])
	复杂度： O(n) space (O(1) if you use two var only), O(n) time.
	相关问题：最大和绝对值[Leetcode Q1749]: 同样用两个值保存最大和最小和，每次找最大最小的绝对值最大值

> 4.字符串的最小编辑距离 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/05.02.html))  ([Leetcode Q72](https://leetcode-cn.com/problems/edit-distance/))

	方法1: dp[i][j]表示从S[:i]到T[:j]的转换. dp[i][0]=i; dp[0][j]=j.
			状态转移: dp[i][j] =min{
					dp[i-1][j] + 1, S[i]不在T[0…j]中，删除操作
					dp[i-1][j-1] + 1/0, S[i]是否等于0T[j]，替换操作
					dp[i][j-1] + 1 , S[i]在T[0…j-1]中增加操作
			即 dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (S[i]!=T[j]))
	复杂度： O(nm) space, O(mn) time.

> 5.交替字符串 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/05.04.html))

	方法1: dp[i][j]表示C[:i+j]由A[:i], B[:j]交替而得
			状态转移: dp[i][j] = 1 if:
							dp[i][j-1]==1 && C[i+j]==B[j] ||
							dp[i-1][j]==1 && C[i+j]==A[i]
					dp[i][j] = 0 otherwise
	复杂度： O(nm) space, O(nm) time.

> 6.最长递增子序列 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/05.06.html)) ([Leetcode Q300](https://leetcode-cn.com/problems/longest-increasing-subsequence))

	方法1: dp[i]表示以A[i]结尾的序列的最长递增子序列. dp[0]=1
			状态转移: dp[j] = max(A[i]+1 for 0<=i<j and A[i]<A[j]). If not exist. A[j]=1
	复杂度： O(n) space, O(n^2) time.
	相关问题：最长公共子序列([Leetcode Q1143])
				Xm=Yn -> LCS(m,n)=LCS(m-1,n-1)+1;
				Xm!=Yn -> LCS(m,n)=max{LCS(m-1,n)+LCS(m,n-1)}
		    最短删除距离([Leetcode Q583]) 等价于求出LCS之后，m+n-2*LCS(m,n)
		    
    方法2：dp+二分查找。维护一个动态的vector，先放入nums。每次遍历nums中的其他值。
          如果n<dp[0],替换dp[0];如果n>dp[-1]，插入最后。否则在dp中找到第一个比dp大的数，替换为n。dp数组一定是单调增加的，其大小为长的序列大小
          但是这个证明比较难理解
    复杂度： O(n) space, O(nlogn) time.      

> 7.硬币组合 ([CC150 Q47](hhttps://www.nowcoder.com/practice/c0503ca0a12d4256af33fce2712d7b24?tpId=8&tqId=11041&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](https://www.cnblogs.com/python27/archive/2013/09/05/3303721.html))

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

> 10.剪绳子 ([剑指offer Q75](https://leetcode-cn.com/problems/jian-sheng-zi-lcof/))

    方法1： dp记录，更新为(max(dp[i], dp[i-k]*d[k]) for all valid k). 主要记得dp[3]的输出跟状态初始并不一样
    复杂度: O(n) space, O(n^2) time.

> 11.数字翻译成字符串 ([剑指offer Q68](https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof))

    方法1：f(i) = f(i-1) + f(i-2)[i-1,i goes for valid val]
    复杂度: O(1) space, O(n) time.
    
    方法2：递归  translateNum(num / 10) + translateNum(num / 100) * (translateNum(num % 100) - 1);
    复杂度: O(n) space, O(n) time.
    
> 12.n个骰子的点数-概率 ([剑指offer Q74](https://leetcode-cn.com/problems/nge-tou-zi-de-dian-shu-lcof/))

    方法1：每多一个骰子，概率都为前面n-1个组成的概率 + 现在这个的概率。这里要注意写法, 前n-1个骰子和为k时，n个骰子时k+1~k+6概率分布贡献1/6
          写的时候，每一个dp数组都是从最小的和开始
    复杂度： O(n) space, O(n^2) time.
    
> 13.接雨水 ([Leetcode Q42](https://leetcode-cn.com/problems/trapping-rain-water))

    方法1: 某个点的雨水量为左右两边（包含自己）高度的最大值中的最小值 - 自身高度。用两个vector分别记录两边的最大值即可
    复杂度： O(n) space, O(n) time
    
> 14_1.最大正方形面积 ([Leetcode Q221](https://leetcode-cn.com/problems/maximal-square))

    方法1: dp[i][j]为右下角每个点为正方形的最大面积。可以证明dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])+1，当nums[i][j]==1成立
    复杂度： O(mn) space, O(mn) time
    
> 14_2.全为1的正方形 ([Leetcode Q1277](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/))

    方法1: 同13_1的递归。同时可以发现dp[i][j]正是以该顶点为右下角的正方形个数
    复杂度： O(mn) space, O(mn) time
   
> 15_1.不同路径 ([Leetcode Q62](https://leetcode-cn.com/problems/unique-paths))

    方法1: dp[i][j] = dp[i-1][j](i!=0) + dp[i][j-1](j!=0)
    复杂度： O(mn) space, O(mn) time
    
    方法2: 一共要走 (m-1)*(n-1)步，其中(m-1)步向下，计算组合数量即可
    复杂度： O(1) space, O(min(m,n)) time
    
> 15_2.不同路径II ([Leetcode Q63](https://leetcode-cn.com/problems/unique-paths-ii))

    方法1: dp[i][j] = dp[i-1][j](i!=0) + dp[i][j-1](j!=0), 但是当nums[i][j] == 1时为0.
    复杂度： O(mn) space(O(1) if use original matrix), O(mn) time
    
> 15_3.最小路径和 ([Leetcode Q64](https://leetcode-cn.com/problems/minimum-path-sum))

    方法1: dp[i][j] = min(dp[i-1][j](i!=0), dp[i][j-1](j!=0))
    复杂度： O(mn) space(O(1) if use original matrix), O(mn) time
    
> 16.不同的二叉搜索树 ([Leetcode Q96](https://leetcode-cn.com/problems/unique-binary-search-trees))

    方法1: dp[i] = sum(dp[j-1]*dp[i-j])
    复杂度： O(n) space, O(n^2) time
    
    方法2: 数学归纳法。dp[i+1] = 2(2n+1)/(n+2) dp[i]
    复杂度： O(1) space, O(n) time
    相似题目：不同的二叉搜索树II([Leetcode Q95]): 递归的把左右子树都求出来，拼接在当前node上
    
> 17.单词拆分 ([Leetcode Q64](https://leetcode-cn.com/problems/word-break))

    方法1: 用一个set保存可行的单词选择。dp[i] = dp[j] && set.contains(s.substr(j, i-j)) for all j. 某个点为true就可设置为true
    复杂度： O(n) space, O(n^2) time
    
> 18.打家劫舍III ([Leetcode Q337](https://leetcode-cn.com/problems/house-robber-iii))

    方法1: 用一个vector<int> res(2)表示取和不取当前node的最大结果。
          res[0] = max(l[0], l[1]) + max(r[0], r[1]) 不取当前node，保证下面都是最大的
          res[1] = root->val + l[0] + r[0] 取当前node，保证下面都是没取左右孩子的
    
> 19.零钱组合 ([Leetcode Q322](https://leetcode-cn.com/problems/coin-change))

    方法1: dp[i] = min(dp[i], dp[i-c]+1) for all c in coins. 初始为amount+1(不可能达到），dp[0] = 0
    复杂度： O(n) space, O(nk) time
    
> 20_1.分割等和子集 ([Leetcode Q416](https://leetcode-cn.com/problems/partition-equal-subset-sum/))

    方法1: 等价于取出子集中n个元素，和为整个和的一般（01背包问题）
    复杂度： O(sum) space, O(n*target) time
    相似题目： 01背包-所有的背包问题都可以化成二维dp数组，然后可以化简为1维dp
    
> 20_2.目标和 ([Leetcode Q494](https://leetcode-cn.com/problems/target-sum/))

    方法1: S=A+B, 现在另B=-B。A-B=target->A=（S+target）/2. 等价于取出子集中n个元素，使和为A。dp求解有多少种方式模板为
                vector<int> dp(sum+1);
                dp[0] = 1;
                for(auto i:nums){
                    for(int j=sum; j>=i; j--)
                        dp[j] += dp[j-i];
                }
                return dp[sum];
    复杂度： O(sum) space, O(n*target) time
    
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

> 1.数值的整数次方 ([剑指offer Q12](https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/)) ([Leetcode Q50](https://leetcode-cn.com/problems/powx-n))

	方法1: 主要考察是否覆盖全部case(0^0, 0^neg, 0^pos, n^0, n^neg, n^pos).
		  注意的是，对于c++，判断浮点数是否为0应留有error
		  对于exp的计算，可以用二分法(x&1==1)
	复杂度： O(1) space, O(logn) time.

> 2.从1到n整数中1出现的次数 ([剑指offer Q31](https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/)) ([Leetcode Q233](https://leetcode-cn.com/problems/number-of-digit-one))

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

> 3.丑数 ([剑指offer Q33](https://leetcode-cn.com/problems/chou-shu-lcof/)) ([Leetcode Q264](https://leetcode-cn.com/problems/ugly-number-ii/))

	方法1: 用三个队列分别表示x2,x3,x5的结果。每次讲三个队列最小的头推出加入输出数组（重复则一起推出）。
			将该数x2,x3,x5之后分别推入三个队列的尾部
			实现的时候可以只采用一个输出数组，并用3个指针指向该输出数组的位置，减少extra space。
	复杂度： O(1) space, O(n) time.
	相似题目：超级丑数 ([剑指offer Q311]）：增加了prime的数量。用同样的方法for loop即可

> 4.不使用加减乘除和判断语句求1～n的和 ([剑指offer Q47](https://leetcode-cn.com/problems/qiu-12n-lcof/))

	方法1: 采用递归. n==0时 n && 不再计算直接返回。主要就是怎么样停止循环
	复杂度： O(1) space, O(logn) time.
	 int res = n;
	 n && (res += Sum_Solution(n-1));
	 return res;

> 5_1.不用加减乘除做加法 ([剑指offer Q48](https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking))

	方法1: 位运算。a=a^b， b=a&b<<1。直到b不为0

> 5_2.整数除法 ([Leetcode Q29](https://leetcode-cn.com/problems/divide-two-integers/))

	方法1: 将a不停的减去b,b<<1,b<<2，res+=1<<i个数。要用long来保存a和b，这样b<<i就不会溢出丢失信息。注意符号判断和越界
	
> 6.二进制float小数 ([CC150 Q26](https://www.nowcoder.com/practice/743853af75fc4026939a682b86535f79?tpId=8&tqId=11020&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2013/01/02/5.2/))

	方法1: 整数部分通过%2再/2一步步向前，小数部分对比1/2^i一步步向后

> 7.无缓存交换 ([CC150 Q60](https://www.nowcoder.com/practice/845ec89145b04b2b855d020d9c3ea2ef?tpId=8&tqId=11054&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2013/02/20/19.1/))

	方法1: b = a - b
		  a = a - b = b
		  b = a + b = a
	
	方法2: a = a^b
		  b = a^b = a^b^b = a
		  a = a^b = a^b^a = b

> 8.得到两数较大值 ([CC150 Q62](https://www.nowcoder.com/practice/b0a82250677a4fabb0bc41053fa05013?tpId=8&tqId=11056&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2013/02/21/19.4/))

	方法1: b = a - b，令b>>31为mask.如果a<b,mask=11..11; 否则mask=00..00
		   b&(b>>31) = a-b if a<b else 0. 返回 a-b&(b>>31) 即可

> 9.阶乘末尾0的个数 ([CC150 Q64](https://www.nowcoder.com/practice/434922f9f4724b97b83c417e884008f1?tpId=8&tqId=11058&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking)) ([CC150 Sol](http://hawstein.com/2013/02/20/19.3/))
                  ([Leetcode Q172](https://leetcode-cn.com/problems/factorial-trailing-zeroes/)) 

	方法1: 等同于只需要计算5的因子数。每次先加上 n/5个，然后让n=n/5,计算更深层的5的个数，直到n为0
	复杂度： O(1) space, O(logn) time.
	
> 10.数字序列中某一位的数 ([剑指offer Q67](https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof)) ([Leetcode Q67](https://leetcode-cn.com/problems/nth-digit/)) 

    方法1：需要归纳规律。1-9有9个数9位；10-99有90个数180位；100-999有900个数2700位。10^digit-10^(digit+1)-1有9*10^digit*(digit+1)位
          找到该n对应的digit，再找到对应的num，再找到对应的位数
    复杂度： O(1) space, O(logn) time.
    
> 11.质数统计 ([Leetcode Q204](https://leetcode-cn.com/problems/count-primes)) 

    方法1：每个数检查一下是否为质数。质数需要从2~sqrt(x)的因子都去做余数，如果余数==0，不为质数
    复杂度： O(1) space, O(n*sqrt(n)) time.
    
    方法2：埃式筛查法。用一个长度为n的数组记录每个值是否为质数，一开始都为true。如果i为质数，则把对应的i的倍数全部更新为非质数
          更新的时候，j从i*i开始，每次+=i，更小的非质数已经被更新过。i只需要遍历2~sqrt(n)
    复杂度： O(n) space, O(nloglog(n)) time.
    
> 12.完全平方数 ([Leetcode Q274](https://leetcode-cn.com/problems/perfect-squares)) 

    方法1：dp[i]保存到每个i位置时最少的组合个数。dp[i] = min(dp[i], dp[i-j*j]) for all j*j<=i. dp[i]初始为i
    复杂度： O(1) space, O(n*sqrt(n)) time.
    
> 13.根号x ([Leetcode Q69](https://leetcode-cn.com/problems/sqrtx)) 

    方法1：二分法查找中点，注意用long以及边界的处理情况
    复杂度： O(1) space, O(logn) time.
    
    方法2：牛顿法。迭代函数为 0.5(xi + x/xi)直到xi和xi+1差距小于阈值
          牛顿法的通俗公式为 xi+1 = xi - f(xi)/f`(xi) ，带入函数x^2-C ->  xi - (xi^2-C)/2xi -> 0.5(xi + x/xi)
    复杂度： O(1) space, O(logn) time.

> 14.可怜的猪 ([Leetcode Q458](https://leetcode-cn.com/problems/poor-pigs)) 
    
    方法1：可推导出最少的数量满足(test/Die + 1)^n >= buckets， 取值即为 ceil(log(buckets) / log(test/die+1))
    复杂度： O(1) space, O(1) time.
    
---
<br />

# <h2 id="14">贪心算法（Greedy Algorithm）</h2>

### 问题及思路

> 1.最大的盛水容器 ([Leetcode Q11](https://leetcode-cn.com/problems/container-with-most-water/))

    方法1: 双指针。每次移动较小值的指针。如果移动较大值的指针，最小高度不变，容积一定减小。因此较小边不可能作为最优的边界， 需要移动
    复杂度： O(1) space, O(n) time
    
> 2_1.跳跃游戏([Leetcode Q55](https://leetcode-cn.com/problems/jump-game))

    方法1: 从后往前看，dp为从每个点开始是否能跳到最后的结果，但是每个都要计算k此
    复杂度： O(n) space, O(nk) time
    
    方法2: 贪心的看，每次到i只要记录能到达的最右边，遍历i的位置即可
    复杂度： O(1) space, O(n) time
    
> 2_2.跳跃游戏II ([Leetcode Q45](https://leetcode-cn.com/problems/jump-game-ii))

    方法1: 贪心算法，每次都向前到最右边能到的边界。等真的到了这个地方，把count++
    复杂度： O(1) space, O(n) time
    
> 3.任务管理器 ([Leetcode Q621](https://leetcode-cn.com/problems/task-scheduler/))

    方法1: 计算出不同任务出现的最大次数t, 并且记录出现了t次的count（用一个dict）
          设想每一排长度为n+1，将出现次数最大的排在每行的头上，其他的插入即可，最后一行不需要排满.至少需要nums.size()次
          次数为 max(nums.size(), (t-1)*(n+1)+count)
    复杂度： O(n) space, O(n) time
    
> 4.根据身高重建队列 ([Leetcode Q406](https://leetcode-cn.com/problems/queue-reconstruction-by-height))

    方法1: 将身高按照高到低排序，相同身高按照前面人的个数升序。每次按照排序插入，插入的位置就是前面人的个数
          用list实现会比vector在插入时快得多（但是list需要找到对应的iterator，不能使用begin()+k)
    复杂度： O(n) space, O(n) time
    
> 5.加油站 ([Leetcode Q134](https://leetcode-cn.com/problems/gas-station/submissions/))

    方法1: 从每一个i开始，往后走，记录sumGas和sumCost。任何时刻如果cost>gas说明走不下去。下一次开始必须从走不下去的新节点开始
          由于是环状，要用余数。如果走过n个节点，那么成功
    复杂度： O(1) space, O(n) time
    
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
	            swap(nums[j], nums[j+1]);
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
	    swap(nums[i], nums[minIndex]);
	}

> 3.插入排序(Insertion Sort) <br>
>
> 简述：每次插入一个数，按照其大小插入对应的位置 <br>
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
> 随机取一个实际时间容易比总是取最后一个更好.
> 平均时间复杂度: O(nlogn) <br>
> 最差时间复杂度: O(n^2) -- 当本来就排好序时 <br>
> 空间复杂度: O(logn) --递归导致 <br>
> 稳定性: 不稳定，交换pivot时可能把中间位置的数移动改变顺序

	void quickSort(vector<int>& nums){
		quickSort(nums,0,nums.size());
	}
	void quickSort(vector<int>& nums, int low, int high){
		if(low<high){
			int p = partition(nums,low,high);
			quickSort(nums,low,p-1);
			quickSort(nums,p,high);
		}
	}
	int partition(vector<int>& nums,int low, int high){
        int pivot = rand() % (end-start+1) + start;  // increase randomness
        swap(nums[pivot], nums[high])
		int i=low-1;
		for(int j=low;j<high;j++){
			if(nums[j]<=nums[high]){
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

    Pass

---
<br />

# <h2 id="16">大数据问题（Big Data）</h2>
### 常见方法
1.hash进行分块求解（通常适用于内存不够的情况）/ 或者直接分段

2.使用堆求最大的k相关问题

3.map-reduce

4.Locality Sensetive Hashing(LSH)

5.随机算法(Randomized Algorithm)

6.bitmap

7.Bloom Filter

8.字典树(Trie)

9.Count-Min Sketch
### 问题及思路

> 1.海量日志数据，提取出某日访问百度次数最多的那个IP ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.02.html))

	数量过多，内存中无法放进全部。采用hash分而治之。
	通过日期将ip提取，hash到每个机器上分别统计
	取出每个机器上最大的结果（因为已经hash过了，相同ip都在同一个机器上）。可使用最大堆

> 2.寻找热门查询，300万个查询字符串中统计最热门的10个查询 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.02.html))

	内存中可以全部放的下。先通过O(n)扫描统计每个查询的次数。再用堆维护
	时间为O(N) + N'*O(logk)， N'为去除重复之后的个数
	相关问题：统计词频最高的100个词（也可使用Trie树），100万个数中最大的100个数

> 3.海量数据分布在100台电脑中，想个办法高效统计出这批数据的TOP10 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.02.html))

	由于数据已经分散。
	方法1: 重新遍历，再hash分配，再用max heap
	方法2: map-reduce，在每块上分别统计，再统一在一起求出现次数

> 4.2.5亿个整数中找出不重复的整数的个数，内存空间不足以容纳这2.5亿个整数 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.06.html))

	将数据分为多个区域（如2^8），每个中使用bitmap统计，内存够用（每个bit代表一个数字）

> 5.5亿个int找它们的中位数 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.06.html))

	将数据从大到小分到不同的机器中。从小机器开始统计个数，不断累加，直到到达中位数

> 6.10万个长度不超过10的单词判断前面是否出现过 ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.09.html))

	1.构建一个trie树（26叉树），每遇到一个词，插入和查询可以一起进行，都是O(1)时间（因为长度为10）
	2.允许错误时也可以用bloom filter

> 7.两个大文件是否有相同url ([程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/06.08.html))

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
来自[程序员编程艺术](http://frank19900731.github.io/ebook/the-art-of-programming-by-july/08.04.html)

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
来自[CC150](http://hawstein.com/2013/03/14/ctci-solutions-contents/)
> 1.往浏览器中输入一个URL后都发生了什么：

	1.浏览器向DNS服务器查找输入URL对应的IP地址。
	2.DNS服务器返回网站的IP地址。
	3.浏览器根据IP地址与目标web服务器在80端口上建立TCP连接
	4.浏览器获取请求页面的html代码。
	5.浏览器在显示窗口内渲染HTML。
	6.窗口关闭时，浏览器终止与服务器的连接。

## 编译
### 问题及思路
来自[github](https://github.com/lawy623/interview)

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
来自([github](https://github.com/lawy623/interview)) ([CC150](http://hawstein.com/2013/03/14/ctci-solutions-contents/))

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
