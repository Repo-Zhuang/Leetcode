# LeetCode笔记

[TOC] 

## 数组

### 27.[移除元素](https://leetcode.cn/problems/remove-element/description/)

**题目：**

给你一个数组 `nums` 和一个值 `val`，你需要**原地**移除所有数值等于 `val` 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 `O(1)` 额外空间并**原地**修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

**说明:**

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以**「引用」**方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

```c++
// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中 该长度范围内 的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
```

**示例 1：**

```C++
输入：nums = [3,2,2,3], val = 3
输出：2, nums = [2,2]
解释：函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。你不需要考虑数组中超出新长度后面的元素。例如，函数返回的新长度为 2 ，而 nums = [2,2,3,3] 或 nums = [2,2,0,0]，也会被视作正确答案。
```

**示例 2：**

```c++
输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,4,0,3]
解释：函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。注意这五个元素可为任意顺序。你不需要考虑数组中超出新长度后面的元素。
```

**提示：**

- `0 <= nums.length <= 100`
- `0 <= nums[i] <= 50`
- `0 <= val <= 100`

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowindex=0;
        int quickindex = 0;
        int n = nums.size();
        for (;quickindex < n; quickindex++) {
            if (nums[quickindex] != val) {
                nums[slowindex++] = nums[quickindex];
            }
        }
        return slowindex;
    }
};
```

----

### 209.[长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/description/)

**题目：**

给定一个含有 `n` 个正整数的数组和一个正整数 `target` **。**

找出该数组中满足其和 `≥ target` 的长度最小的 **连续子数组** `[numsl, numsl+1, ..., numsr-1, numsr]` ，并返回其长度**。**如果不存在符合条件的子数组，返回 `0` 。

**示例 1：**

```C++
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
```

**示例 2：**

```C++
输入：target = 4, nums = [1,4,4]
输出：1
```

**示例 3：**

```C++
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0 
```

**提示：**

- `1 <= target <= 109`
- `1 <= nums.length <= 105`
- `1 <= nums[i] <= 105`

**进阶：**

- 如果你已经实现 `O(n)` 时间复杂度的解法, 请尝试设计一个 `O(nlog(n))` 时间复杂度的解法。

**思路：**

利用滑动窗口，当前面的指针超过数组大小时，说明此时数组元素和不满足大于target的条件，故此为终止条件。

当找到满足条件的子数组时，要从前面不断收缩窗口，以找到最小长度，假设只剩一个元素时仍然满足条件，此时

`j++`后`sum`和为`0`，相当于从`0`开始加。

**C++代码实现：**

```C++
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int Minlen = INT32_MAX;
        int Curlen;
        
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= target)  {
                Curlen = (i - j + 1);
                Minlen = Minlen < Curlen ? Minlen : Curlen;
                sum -= nums[j++];
            }
        }
        return Minlen == INT32_MAX ? 0 : Minlen;
    }
};
```

---

### 383.[赎金信](https://leetcode.cn/problems/ransom-note/description/)

**题目：**

给你两个字符串：`ransomNote` 和 `magazine` ，判断 `ransomNote` 能不能由 `magazine` 里面的字符构成。

如果可以，返回 `true` ；否则返回 `false` 。

`magazine` 中的每个字符只能在 `ransomNote` 中使用一次。

**示例 1：**

```C++
输入：ransomNote = "a", magazine = "b"
输出：false
```

**示例 2：**

```C++
输入：ransomNote = "aa", magazine = "ab"
输出：false
```

**示例 3：**

```C++
输入：ransomNote = "aa", magazine = "aab"
输出：true
```

**提示：**

- `1 <= ransomNote.length, magazine.length <= 105`
- `ransomNote` 和 `magazine` 由小写英文字母组成

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int A[26] = {0};
        for (auto c: magazine) {
            A[c - 'a']++;
        }
        for (auto c: ransomNote) {
            if (--A[c - 'a'] < 0) return false;
        }
        return true;
    }
};
```

----

### 670.[最大交换](https://leetcode.cn/problems/maximum-swap/description/)

**题目：**

给定一个非负整数，你**至多**可以交换一次数字中的任意两位。返回你能得到的最大值。

**示例 1 :**

```C++
输入: 2736
输出: 7236
解释: 交换数字2和数字7。
```

**示例 2 :**

```C++
输入: 9973
输出: 9973
解释: 不需要交换。
```

**注意:**

1. 给定数字的范围是 [0, 108]

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    int maximumSwap(int num) {
        string charArray = to_string(num);
        int size = charArray.size();
        int max;
        for (int i =0; i < size; i++) {
            max = i;
            for (int j = i ; j < size; j++) {
                if (charArray[j] >= charArray[max]) {
                    max = j;
                }
            }
            if (max != i && charArray[i] != charArray[max]) {
                swap(charArray[i], charArray[max]);
                break;
            }
        }
        return stoi(charArray);
    }
};
```

----

### 704.[二分查找](https://leetcode.cn/problems/binary-search/description/)

**题目：**

给定一个 `n` 个元素有序的（升序）整型数组 `nums` 和一个目标值 `target` ，写一个函数搜索 `nums` 中的 `target`，如果目标值存在返回下标，否则返回 `-1`。
**示例 1:**

```C++
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4
```

**示例 2:**

```C++
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1 
```

**提示：**

1. 你可以假设 `nums` 中的所有元素是不重复的。
2. `n` 将在 `[1, 10000]`之间。
3. `nums` 的每个元素都将在 `[-9999, 9999]`之间。

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left +(right - left) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else return middle;
        }
        return -1;  
    }
};
```

---

### 977.[有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array/description/)

**题目：**

给你一个按 **非递减顺序** 排序的整数数组 `nums`，返回 **每个数字的平方** 组成的新数组，要求也按 **非递减顺序** 排序。

**示例 1：**

```C++
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]
排序后，数组变为 [0,1,9,16,100]
```

**示例 2：**

```C++
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121] 
```

**提示：**

- `1 <= nums.length <= 104`
- `-104 <= nums[i] <= 104`
- `nums` 已按 **非递减顺序** 排序

**进阶：**

- 请你设计时间复杂度为 `O(n)` 的算法解决本问题

**思路：**

由于数组已经按照非递减顺序排序了，那么平方后的大小肯定在数组左右两边产生。故只需使用双指针指向第一个元素和最后一次元素，

两两平方后开始比较，大的元素进入容器，指针向中间移动，需时间和空间的复杂度都为$O(n)$

**C++代码实现：**

```C++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> A(n, 0);
        int i = 0;
        int j = n - 1;
        int k = n - 1;
        while (i <= j) {
            if (pow(nums[i], 2) >= pow(nums[j], 2)) {
                A[k--] = pow(nums[i], 2);
                i++;
            }
            else {
                A[k--] = pow(nums[j], 2);
                j--;
            }
        }
        return A;
    }
};
```



---

### 1619.[删除某些元素后的数组均值](https://leetcode.cn/problems/mean-of-array-after-removing-some-elements/description/)

**题目：**

给你一个整数数组 `arr` ，请你删除最小 `5%` 的数字和最大 `5%` 的数字后，剩余数字的平均值。

与 **标准答案** 误差在 `10-5` 的结果都被视为正确结果。

**示例 1：**

```C++
输入：arr = [1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,3]
输出：2.00000
解释：删除数组中最大和最小的元素后，所有元素都等于 2，所以平均值为 2 。
```

**示例 2：**

```C++
输入：arr = [6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0]
输出：4.00000
```

**示例 3：**

```C++
输入：arr = [6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4]
输出：4.77778
```

**示例 4：**

```C++
输入：arr = [9,7,8,7,7,8,4,4,6,8,8,7,6,8,8,9,2,6,0,0,1,10,8,6,3,3,5,1,10,9,0,7,10,0,10,4,1,10,6,9,3,6,0,0,2,7,0,6,7,2,9,7,7,3,0,1,6,1,10,3]
输出：5.27778
```

**示例 5：**

```
输入：arr = [4,8,4,10,0,7,1,3,7,8,8,3,4,1,6,2,1,1,8,0,9,8,0,3,9,10,3,10,1,10,7,3,2,1,4,9,10,7,6,4,0,8,5,1,2,1,6,2,5,0,7,10,9,10,3,7,10,5,8,5,7,6,7,6,10,9,5,10,5,5,7,2,10,7,7,8,2,0,1,1]
输出：5.29167
```

**提示：**

- `20 <= arr.length <= 1000`
- `arr.length` 是 `20` 的 **倍数** 
- `0 <= arr[i] <= 105`

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    double trimMean(vector<int>& arr) {
        int len = arr.size();
        int k = len / 20;
        sort(arr.begin(), arr.end());
        double result = 0;
        for (int i = k ; i < len - k; i++) {
            result += arr[i];
        }
        return result / (len - 2*k);
       
       /*  int n = arr.size();
        sort(arr.begin(), arr.end());
        double partialSum = accumulate(arr.begin() + n / 20, arr.end() -n / 20, 0);
        return partialSum / (n * 0.9); */
    }
};
```

---

## 链表

### 19.[删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/)

**题目：**

给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

**示例 1：**

![img](https://picture-1314086598.cos.ap-guangzhou.myqcloud.com//img/remove_ex1.jpg)



```C++
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

**示例 2：**

```C++
输入：head = [1], n = 1
输出：[]
```

**示例 3：**

```C++
输入：head = [1,2], n = 1
输出：[1]
```

**提示：**

- 链表中结点的数目为 `sz`
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

**进阶：**你能尝试使用一趟扫描实现吗？

**思路：**

**C++代码实现：**

```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* SlowPtr = dummyNode;
        ListNode* QuickPtr = dummyNode;
        ListNode* tmp;

        while (n--) QuickPtr = QuickPtr->next;
        while (QuickPtr->next != nullptr) {
            QuickPtr = QuickPtr->next;
            SlowPtr = SlowPtr->next;
        }
        tmp = SlowPtr->next;
        SlowPtr->next = SlowPtr->next->next;
        delete tmp;
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};
```

---

### 24.[两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/description/)

**题目：**

给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

**示例 1：**

![img](https://picture-1314086598.cos.ap-guangzhou.myqcloud.com//img/swap_ex1.jpg)

```C++
输入：head = [1,2,3,4]
输出：[2,1,4,3]
```

**示例 2：**

```c++
输入：head = []
输出：[]
```

**示例 3：**

```C++
输入：head = [1]
输出：[1]
```

**提示：**

- 链表中节点的数目在范围 `[0, 100]` 内
- `0 <= Node.val <= 100`

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        ListNode* tmp;
        while (cur->next && cur->next->next)
        {
            tmp = cur->next;
            cur->next = cur->next->next;
            tmp ->next = tmp->next->next;
            cur->next->next = tmp;
            cur = cur->next->next;
        }
        
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};
```

---

### 142.[环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/description/)

**题目：**

给定一个链表的头节点  `head` ，返回链表开始入环的第一个节点。 *如果链表无环，则返回 `null`。*

如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 `pos` 来表示链表尾连接到链表中的位置（**索引从 0 开始**）。如果 `pos` 是 `-1`，则在该链表中没有环。**注意：`pos` 不作为参数进行传递**，仅仅是为了标识链表的实际情况。

**不允许修改** 链表。

**示例 1：**

![img](https://picture-1314086598.cos.ap-guangzhou.myqcloud.com//img/circularlinkedlist.png)

```C++
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
```

**示例 2：**

![img](https://picture-1314086598.cos.ap-guangzhou.myqcloud.com//img/circularlinkedlist_test2.png)

```C++
输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
```

**示例 3：**

![img](https://picture-1314086598.cos.ap-guangzhou.myqcloud.com//img/circularlinkedlist_test3.png)

```C++
输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。
```

**提示：**

- 链表中节点的数目范围在范围 `[0, 104]` 内
- `-105 <= Node.val <= 105`
- `pos` 的值为 `-1` 或者链表中的一个有效索引

**进阶：**你是否可以使用 `O(1)` 空间解决此题？

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* QuickPtr = head;
        ListNode* SlowPtr = head;
        while (QuickPtr != nullptr && QuickPtr->next!= nullptr) {
            QuickPtr = QuickPtr->next->next;
            SlowPtr = SlowPtr->next;
            if (QuickPtr ==  SlowPtr) {
                ListNode* Pcur = QuickPtr;
                ListNode* Phead = head;
                while (Pcur != Phead) {
                    Pcur = Pcur->next;
                    Phead = Phead->next;
                }
                return Pcur;
            }
        }
        return NULL;  
    }
};
```

---

### 160.[相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/description/)

**题目：**

给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 `null` 。

图示两个链表在节点 `c1` 开始相交**：**

[![img](https://picture-1314086598.cos.ap-guangzhou.myqcloud.com//img/160_statement.png)](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/160_statement.png)

题目数据 **保证** 整个链式结构中不存在环。

**注意**，函数返回结果后，链表必须 **保持其原始结构** 。

**自定义评测：**

**评测系统** 的输入如下（你设计的程序 **不适用** 此输入）：

- `intersectVal` - 相交的起始节点的值。如果不存在相交节点，这一值为 `0`
- `listA` - 第一个链表
- `listB` - 第二个链表
- `skipA` - 在 `listA` 中（从头节点开始）跳到交叉节点的节点数
- `skipB` - 在 `listB` 中（从头节点开始）跳到交叉节点的节点数

评测系统将根据这些输入创建链式数据结构，并将两个头节点 `headA` 和 `headB` 传递给你的程序。如果程序能够正确返回相交节点，那么你的解决方案将被 **视作正确答案** 。

 

**示例 1：**

[![img](https://picture-1314086598.cos.ap-guangzhou.myqcloud.com//img/160_example_1_1.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_1.png)

```C++
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,6,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
— 请注意相交节点的值不为 1，因为在链表 A 和链表 B 之中值为 1 的节点 (A 中第二个节点和 B 中第三个节点) 是不同的节点。换句话说，它们在内存中指向两个不同的位置，而链表 A 和链表 B 中值为 8 的节点 (A 中第三个节点，B 中第四个节点) 在内存中指向相同的位置。
```

 

**示例 2：**

[![img](https://picture-1314086598.cos.ap-guangzhou.myqcloud.com//img/160_example_2.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_2.png)

```C++
输入：intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
输出：Intersected at '2'
解释：相交节点的值为 2 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [1,9,1,2,4]，链表 B 为 [3,2,4]。
在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
```

**示例 3：**

[![img](https://picture-1314086598.cos.ap-guangzhou.myqcloud.com//img/160_example_3.png)](https://assets.leetcode.com/uploads/2018/12/13/160_example_3.png)

```C++
输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
输出：null
解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。
由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
这两个链表不相交，因此返回 null 。
```

**提示：**

- `listA` 中节点数目为 `m`
- `listB` 中节点数目为 `n`
- `1 <= m, n <= 3 * 104`
- `1 <= Node.val <= 105`
- `0 <= skipA <= m`
- `0 <= skipB <= n`
- 如果 `listA` 和 `listB` 没有交点，`intersectVal` 为 `0`
- 如果 `listA` 和 `listB` 有交点，`intersectVal == listA[skipA] == listB[skipB]`

**进阶：**你能否设计一个时间复杂度 `O(m + n)` 、仅用 `O(1)` 内存的解决方案？

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0;
        int sizeB = 0;
        ListNode* cur = headA;
        int n;
        while (cur != NULL) {
            cur = cur->next;
            sizeA++;
        }
        cur = headB;
        while (cur != NULL) {
            cur = cur->next;
            sizeB++;
        }
        std::cout << sizeA-sizeB<<endl;
        n = sizeA > sizeB ? (sizeA - sizeB) : (sizeB - sizeA);
        if (sizeA > sizeB) {
            while (n--) headA = headA->next;
        }
        else {
            while (n--) headB = headB->next;
        }
        while(headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
```

---

### 203.[移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/description/)

**题目：**

给你一个链表的头节点 `head` 和一个整数 `val` ，请你删除链表中所有满足 `Node.val == val` 的节点，并返回 **新的头节点** 。

**示例 1：**

![img](https://picture-1314086598.cos.ap-guangzhou.myqcloud.com//img/removelinked-list.jpg)

```C++
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
```

**示例 2：**

```C++
输入：head = [], val = 1
输出：[]
```

**示例 3：**

```C++
输入：head = [7,7,7,7], val = 7
输出：[]
```

**提示：**

- 列表中的节点数目在范围 `[0, 104]` 内
- `1 <= Node.val <= 50`
- `0 <= val <= 50`

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if (val == cur->next->val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else cur = cur->next;
        } 
        head = dummyHead->next;
        delete dummyHead;
        return head;
	}
};
```

---

### 206.[反转链表](https://leetcode.cn/problems/reverse-linked-list/description/)

**题目：**

给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表。

**示例 1：**

![img](https://picture-1314086598.cos.ap-guangzhou.myqcloud.com//img/rev1ex1.jpg)

```C++
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
```

**示例 2：**

![img](https://picture-1314086598.cos.ap-guangzhou.myqcloud.com//img/rev1ex2.jpg)

```C++
输入：head = [1,2]
输出：[2,1]
```

**示例 3：**

```C++
输入：head = []
输出：[]
```

**提示：**

- 链表中节点的数目范围是 `[0, 5000]`
- `-5000 <= Node.val <= 5000`

**进阶：**链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* tmp;
        while (cur) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    //递归法
    /* ListNode* reverse(ListNode* pre,ListNode* cur){
        if(cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // pre = cur;
        // cur = temp;
        return reverse(cur,temp);
    }
    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化是一样的逻辑
        // ListNode* cur = head;
        // ListNode* pre = NULL;
        return reverse(NULL, head);
    } */
};
```

---

### 707.[设计链表](https://leetcode.cn/problems/design-linked-list/description/)

**题目：**

设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：`val` 和 `next`。`val` 是当前节点的值，`next` 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 `prev` 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：

- get(index)：获取链表中第 `index` 个节点的值。如果索引无效，则返回`-1`。
- addAtHead(val)：在链表的第一个元素之前添加一个值为 `val` 的节点。插入后，新节点将成为链表的第一个节点。
- addAtTail(val)：将值为 `val` 的节点追加到链表的最后一个元素。
- addAtIndex(index,val)：在链表中的第 `index` 个节点之前添加值为 `val` 的节点。如果 `index` 等于链表的长度，则该节点将附加到链表的末尾。如果 `index` 大于链表长度，则不会插入节点。如果`index`小于0，则在头部插入节点。
- deleteAtIndex(index)：如果索引 `index` 有效，则删除链表中的第 `index` 个节点。

**示例：**

```C++
MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-> 3
linkedList.get(1);            //返回3
```

 

**提示：**

- 所有`val`值都在 `[1, 1000]` 之内。
- 操作次数将在 `[1, 1000]` 之内。
- 请不要使用内置的 LinkedList 库。

**思路：**

**C++代码实现：**

```C++
class MyLinkedList {
public:
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode(int val):val(val), next(NULL){}
    };
    
    MyLinkedList() {
        _dummyHead = new ListNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index > _size -1)
            return -1;
        ListNode* cur = _dummyHead->next;
        while (index--) {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* NewNode = new ListNode(val);
        NewNode->next = _dummyHead->next;
        _dummyHead->next = NewNode;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* NewNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = NewNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > _size) return;
        if (index < 0) index = 0;
        
        ListNode* NewNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        NewNode->next = cur->next;
        cur->next = NewNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= _size)
            return;
        ListNode* tmp;
        ListNode* cur = _dummyHead;
        while (index--) {
            cur = cur->next;
        }
        tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        _size--;
    }
private:
    int _size;
    ListNode* _dummyHead;
};
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```

----

## 哈希表

### 5.[两数之和](https://leetcode.cn/problems/two-sum/description/)

**题目：**

给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** *`target`* 的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

**示例 1：**

```C++
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**示例 2：**

```C++
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

**示例 3：**

```C++
输入：nums = [3,3], target = 6
输出：[0,1]
```

**提示：**

- `2 <= nums.length <= 104`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`
- **只会存在一个有效答案**

**进阶：**你可以想出一个时间复杂度小于 `O(n2)` 的算法吗？

----

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map <int,int> map;
        for(int i = 0; i < nums.size(); i++) {
            // 遍历当前元素，并在map中寻找是否有匹配的key
            auto iter = map.find(target - nums[i]); 
            if(iter != map.end()) {
                return {iter->second, i};
            }
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i)); 
        }
        return {};
    }
};
```

### 15.[三数之和](https://leetcode.cn/problems/3sum/description/)

**题目：**

给你一个整数数组 `nums` ，判断是否存在三元组 `[nums[i], nums[j], nums[k]]` 满足 `i != j`、`i != k` 且 `j != k` ，同时还满足 `nums[i] + nums[j] + nums[k] == 0` 。请

你返回所有和为 `0` 且不重复的三元组。

**注意：**答案中不可以包含重复的三元组。

**示例 1：**

```C++
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
```

**示例 2：**

```C++
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
```

**示例 3：**

```
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
```

**提示：**

- `3 <= nums.length <= 3000`
- `-105 <= nums[i] <= 105`

**思路：**

**C++代码：**

```C++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> A;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() ; i++) {
            if (nums[i] > 0) return A;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int r = nums.size() - 1;
            while (j < r) {
                if (nums[i] + nums[j] + nums[r] < 0) j++;
                else if (nums[i] + nums[j] + nums[r] > 0) r--;
                else {
                    A.push_back(vector<int>{nums[i], nums[j], nums[r]});
                    while (r > j && nums[j] == nums[j + 1]) j++;
                    while (r > j && nums[r] == nums[r - 1]) r--;
                    r--;
                    j++;
                }
            }
        }
        return A;
    }
};
```

---

### 18.[四数之和](https://leetcode.cn/problems/4sum/description/)

**题目：**

给你一个由 `n` 个整数组成的数组 `nums` ，和一个目标值 `target` 。请你找出并返回满足下述全部条件且**不重复**的四元组 `[nums[a], nums[b], nums[c], nums[d]]` （若两个四元组元素一一对应，则认为两个四元组重复）：

- `0 <= a, b, c, d < n`
- `a`、`b`、`c` 和 `d` **互不相同**
- `nums[a] + nums[b] + nums[c] + nums[d] == target`

你可以按 **任意顺序** 返回答案 。

**示例 1：**

```C++
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**示例 2：**

```C++
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
```

**提示：**

- `1 <= nums.length <= 200`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`

**思路：**

**C++代码：**

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // 剪枝处理
            if (nums[k] > target && nums[k] >= 0 && target >= 0) {
            	break; // 这里使用break，统一通过最后的return返回
            }
            // 对nums[k]去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 2级剪枝处理
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0 && target >= 0) {
                    break;
                }
                // 对nums[i]去重
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    } else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};
```

---

### 202.[快乐数](https://leetcode.cn/problems/happy-number/description/)

**题目：**

编写一个算法来判断一个数 `n` 是不是快乐数。

**「快乐数」** 定义为：

- 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
- 然后重复这个过程直到这个数变为 1，也可能是 **无限循环** 但始终变不到 1。
- 如果这个过程 **结果为** 1，那么这个数就是快乐数。

如果 `n` 是 *快乐数* 就返回 `true` ；不是，则返回 `false` 。

**示例 1：**

```C++
输入：n = 19
输出：true
解释：
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
```

**示例 2：**

```C++
输入：n = 2
输出：false
```

**提示：**

- `1 <= n <= 231 - 1`

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        while(n != 1) {
            int Newn= 0;
            while (n) {
                Newn += pow(n % 10, 2);
                n = n / 10;
            }
            if (set.find(Newn) != set.end()) return false;
            set.insert(Newn);
            n = Newn;
        }
        return true;
    }
};
```

---

### 349.[两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/description/)

**题目：**

给定两个数组 `nums1` 和 `nums2` ，返回 *它们的交集* 。输出结果中的每个元素一定是 **唯一** 的。我们可以 **不考虑输出结果的顺序** 。

**示例 1：**

```c++
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
```

**示例 2：**

```C++
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
```

**提示：**

- `1 <= nums1.length, nums2.length <= 1000`
- `0 <= nums1[i], nums2[i] <= 1000`

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> setnums1(nums1.begin(), nums1.end());

        for (int k: nums2) {
            if (setnums1.find(k) != setnums1.end()) {
                result.insert(k);
            }
        }
        return vector<int>(result.begin(), result.end());
    }       
};
```

---

### 454.[四数相加 II](https://leetcode.cn/problems/4sum-ii/description/)

**题目：**

给你四个整数数组 `nums1`、`nums2`、`nums3` 和 `nums4` ，数组长度都是 `n` ，请你计算有多少个元组 `(i, j, k, l)` 能满足：

- `0 <= i, j, k, l < n`
- `nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0`

**示例 1：**

```C++
输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
输出：2
解释：
两个元组如下：
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
```

**示例 2：**

```C++
输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
输出：1
```

 **提示：**

- `n == nums1.length`
- `n == nums2.length`
- `n == nums3.length`
- `n == nums4.length`
- `1 <= n <= 200`
- `-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228`

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> map;
        //
        for (int num1: nums1){
            for (int num2: nums2){
                map[num1 + num2]++;
            }
        }
        int count = 0;
        for (int num3: nums3){
            for (int num4: nums4){
                if (map.find(-(num3 + num4)) != map.end()) 
                    count += map[-(num3 + num4)];
            }
        } 
        return count;
    }
};
```

---

###  1636.[按照频率将数组升序排序](https://leetcode.cn/problems/sort-array-by-increasing-frequency/description/)

**题目：**

给你一个整数数组 `nums` ，请你将数组按照每个值的频率 **升序** 排序。如果有多个值的频率相同，请你按照数值本身将它们 **降序** 排序。 

请你返回排序后的数组。

**示例 1：**

```C++
输入：nums = [1,1,2,2,2,3]
输出：[3,1,1,2,2,2]
解释：'3' 频率为 1，'1' 频率为 2，'2' 频率为 3 。
```

**示例 2：**

```C++
输入：nums = [2,3,1,3,2]
输出：[1,3,3,2,2]
解释：'2' 和 '3' 频率都为 2 ，所以它们之间按照数值本身降序排序。
```

**示例 3：**

```C++
输入：nums = [-1,1,-6,4,5,-6,1,4,1]
输出：[5,-1,4,4,-6,-6,1,1,1]
```

**提示：**

- `1 <= nums.length <= 100`
- `-100 <= nums[i] <= 100`

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int num: nums) {
            map[num]++;
        }
        sort(nums.begin(), nums.end(), [&](int a, int b){
            if (map[a] != map[b]) return map[a] < map[b];
            return a > b;
        } );
        
        return nums;
    }
};
```

---

## 字符串

### 28.实现 strStr()

**题目：**

给你两个字符串 `haystack` 和 `needle` ，请你在 `haystack` 字符串中找出 `needle` 字符串的第一个匹配项的下标（下标从 0 开始）。如果 `needle` 不是 `haystack` 的一部分，则返回 `-1` 。

**示例 1：**

```C++
输入：haystack = "sadbutsad", needle = "sad"
输出：0
解释："sad" 在下标 0 和 6 处匹配。
第一个匹配项的下标是 0 ，所以返回 0 。
```

**示例 2：**

```C++
输入：haystack = "leetcode", needle = "leeto"
输出：-1
解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1。
```

**提示：**

- `1 <= haystack.length, needle.length <= 104`
- `haystack` 和 `needle` 仅由小写英文字符组成

**思路：**

典型的KMP算法。

**C++代码实现：**

```c++
class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++) { // 注意i从1开始
            while (j >= 0 && s[i] != s[j + 1]) { // 前后缀不相同了
                j = next[j]; //向前回退
            }
            if (s[i] == s[j + 1]) { // 找到相同的前后缀
                j++;
            }
            next[i] = j; // 将j（前缀的长度）赋给next[i]
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1; // // 因为next数组里记录的起始位置为-1
        for (int i = 0; i < haystack.size(); i++) { // 注意i就从0开始
            while(j >= 0 && haystack[i] != needle[j + 1]) { // 不匹配
                j = next[j]; // j 寻找之前匹配的位置
            }
            if (haystack[i] == needle[j + 1]) { // 匹配，j和i同时向后移动
                j++; // i的增加在for循环里
            }
            if (j == (needle.size() - 1) ) { // 文本串s里出现了模式串t
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
```

---

### 150.[逆波兰表达式求值](https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/)

**题目：**

根据[ 逆波兰表示法](https://baike.baidu.com/item/逆波兰式/128437)，求表达式的值。

有效的算符包括 `+`、`-`、`*`、`/` 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

**注意** 两个整数之间的除法只保留整数部分。

可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

**示例 1：**

```C++
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
```

**示例 2：**

```C++
输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
```

**示例 3：**

```C++
输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

**提示：**

- `1 <= tokens.length <= 104`
- `tokens[i]` 是一个算符（`"+"`、`"-"`、`"*"` 或 `"/"`），或是在范围 `[-200, 200]` 内的一个整数

**逆波兰表达式：**

逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

- 平常使用的算式则是一种中缀表达式，如 `( 1 + 2 ) * ( 3 + 4 )` 。
- 该算式的逆波兰表达式写法为 `( ( 1 2 + ) ( 3 4 + ) * )` 。

逆波兰表达式主要有以下两个优点：

- 去掉括号后表达式无歧义，上式即便写成 `1 2 + 3 4 + * `也可以依据次序计算出正确结果。
- 适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> cal;//用long型防止int型数据运算溢出
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long num1 = cal.top();
                cal.pop();
                long num2 = cal.top();
                cal.pop();
                if (tokens[i] == "+") cal.push(num2 + num1);
                if (tokens[i] == "-") cal.push(num2 - num1);
                if (tokens[i] == "*") cal.push(num2 * num1);
                if (tokens[i] == "/") cal.push(num2 / num1);
            }
            else {
                cal.push(stoi(tokens[i]));
            }
        }
        return cal.top();
    }
};
```

---

### 151.[反转字符串中的单词](https://leetcode.cn/problems/reverse-words-in-a-string/description/)

**题目:**

给你一个字符串 `s` ，请你反转字符串中 **单词** 的顺序。

**单词** 是由非空格字符组成的字符串。`s` 中使用至少一个空格将字符串中的 **单词** 分隔开。

返回 **单词** 顺序颠倒且 **单词** 之间用单个空格连接的结果字符串。

**注意：**输入字符串 `s`中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

**示例 1：**

```c++
输入：s = "the sky is blue"
输出："blue is sky the"
```

**示例 2：**

```C++
输入：s = "  hello world  "
输出："world hello"
解释：反转后的字符串中不能存在前导空格和尾随空格。
```

**示例 3：**

```C++
输入：s = "a good   example"
输出："example good a"
解释：如果两个单词间有多余的空格，反转后的字符串需要将单词间的空格减少到仅有一个。
```

**提示：**

- `1 <= s.length <= 104`
- `s` 包含英文大小写字母、数字和空格 `' '`
- `s` 中 **至少存在一个** 单词

**进阶：**如果字符串在你使用的编程语言中是一种可变数据类型，请尝试使用 `O(1)` 额外空间复杂度的 **原地** 解法。

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        //去除多余空格，用快慢指针
        int p = 0;
        for (int q = 0; q < n; q++) {
            if (s[q] != ' ') {
                //如果不是第一单词，前面加空格
                if (p != 0) s[p++] = ' ';
                while (s[q] != ' ' && q < n) {
                        s[p++] = s[q++];
                }    
            }
        }
        //反转字符串
        s.resize(p);
        reverse(s.begin(), s.end()); 
        //反转每个单词
        for (int i = 0, j = 0; i < s.size(); i++) {
            if(s[i + 1] == ' ' || i == s.size() - 1) {
                reverse(s.begin() + j, s.begin() + i + 1);
                j = i + 2;
            }
        }
        //最后赋予0
        return s;
    }
};
```

---

### 242.[有效的字母异位词](https://leetcode.cn/problems/valid-anagram/description/)

**题目：**

给定两个字符串 `*s*` 和 `*t*` ，编写一个函数来判断 `*t*` 是否是 `*s*` 的字母异位词。

**注意：**若 `*s*` 和 `*t*` 中每个字符出现的次数都相同，则称 `*s*` 和 `*t*` 互为字母异位词。

**示例 1:**

```c++
输入: s = "anagram", t = "nagaram"
输出: true
```

**示例 2:**

```C++
输入: s = "rat", t = "car"
输出: false
```

**提示:**

- `1 <= s.length, t.length <= 5 * 104`
- `s` 和 `t` 仅包含小写字母

**进阶:** 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        int A[26] = {0};
        for (int i = 0; i < s.length(); i++) {
            A[s[i] - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            A[t[i] - 'a']--;
        }
        for (int count: A) {
            if (count != 0) return false;
        }
        return true;
    }
};
```

---

### 344.[反转字符串](https://leetcode.cn/problems/reverse-string/description/)

**题目：**

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 `s` 的形式给出。

不要给另外的数组分配额外的空间，你必须**[原地](https://baike.baidu.com/item/原地算法)修改输入数组**、使用 O(1) 的额外空间解决这一问题。

**示例 1：**

```c++
输入：s = ["h","e","l","l","o"]
输出：["o","l","l","e","h"]
```

**示例 2：**

```C++
输入：s = ["H","a","n","n","a","h"]
输出：["h","a","n","n","a","H"]
```

**提示：**

- `1 <= s.length <= 105`
- `s[i]` 都是 [ASCII](https://baike.baidu.com/item/ASCII) 码表中的可打印字符

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            swap(s[i], s[n - i - 1]);
        }
    }
};
```

---

### 459.[重复的子字符串](https://leetcode.cn/problems/repeated-substring-pattern/description/)

**题目：**

给定一个非空的字符串 `s` ，检查是否可以通过由它的一个子串重复多次构成。

**示例 1:**

```C++
输入: s = "abab"
输出: true
解释: 可由子串 "ab" 重复两次构成。
```

**示例 2:**

```C++
输入: s = "aba"
输出: false
```

**示例 3:**

```C++
输入: s = "abcabcabcabc"
输出: true
解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
```

**提示：**

- `1 <= s.length <= 104`
- `s` 由小写英文字母组成

**思路：**

**C++代码实现：**

```C++
```

---

---

### 541.[反转字符串 II](https://leetcode.cn/problems/reverse-string-ii/description/)

**题目：**

给定一个字符串 `s` 和一个整数 `k`，从字符串开头算起，每计数至 `2k` 个字符，就反转这 `2k` 字符中的前 `k` 个字符。

- 如果剩余字符少于 `k` 个，则将剩余字符全部反转。
- 如果剩余字符小于 `2k` 但大于或等于 `k` 个，则反转前 `k` 个字符，其余字符保持原样。

**示例 1：**

```C++
输入：s = "abcdefg", k = 2
输出："bacdfeg"
```

**示例 2：**

```C++
输入：s = "abcd", k = 2
输出："bacd"
```

**提示：**

- `1 <= s.length <= 104`
- `s` 仅由小写英文组成
- `1 <= k <= 104`

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
            } 
            else {
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};		
```

---

### 777.[在LR字符串中交换相邻字符](https://leetcode.cn/problems/swap-adjacent-in-lr-string/description/)

**题目：**

在一个由 `'L'` , `'R'` 和 `'X'` 三个字符组成的字符串（例如`"RXXLRXRXL"`）中进行移动操作。一次移动操作指用一个`"LX"`替换一个`"XL"`，或者用一个`"XR"`替换一个`"RX"`。现给定起始字符串`start`和结束字符串`end`，请编写代码，当且仅当存在一系列移动操作使得`start`可以转换成`end`时， 返回`True`。

**示例 :**

```C++
输入: start = "RXXLRXRXL", end = "XRLXXRRLX"
输出: True
解释:
我们可以通过以下几步将start转换成end:
RXXLRXRXL ->
XRXLRXRXL ->
XRLXRXRXL ->
XRLXXRRXL ->
XRLXXRRLX
```

**提示：**

- `1 <= len(start) = len(end) <= 10000`。
- `start`和`end`中的字符串仅限于`'L'`, `'R'`和`'X'`。

**思路：**

根据题意，我们每次移动要么是将 XL 变为 LX，要么是将 RX 变为 XR，而该两者操作可分别看做将 L 越过多个 X 向左移动，将 R 越过多个 X 向右移动。

因此在 start 和 end 中序号相同的 L 和 R 必然满足坐标性质：

序号相同的 L : start 的下标不小于 end 的下标（即 L 不能往右移动）
序号相同的 R : start 的下标不大于 end 的下标（即 R 不能往左移动）
其中「序号」是指在 LR 字符串中出现的相对顺序。		

**C++代码实现：**

```C++
class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.length(), i = 0, j = 0;
        while (i < n || j < n) {
            while (i < n && start[i] == 'X') i++;
            while (j < n && end[j] == 'X') j++;
            if (i == n || j == n) return i == j;
            if (start[i] != end[j]) return false;
            if (start[i] == 'L' && i < j) return false;
            if (start[i] == 'R' && i > j) return false;
            i++; j++;
        }
        return i == j;
    }
};
```

---

### 921.[使括号有效的最少添加](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/description/)

**题目：**

只有满足下面几点之一，括号字符串才是有效的：

- 它是一个空字符串，或者
- 它可以被写成 `AB` （`A` 与 `B` 连接）, 其中 `A` 和 `B` 都是有效字符串，或者
- 它可以被写作 `(A)`，其中 `A` 是有效字符串。

给定一个括号字符串 `s` ，移动N次，你就可以在字符串的任何位置插入一个括号。

- 例如，如果 `s = "()))"` ，你可以插入一个开始括号为 `"(()))"` 或结束括号为 `"())))"` 。

返回 *为使结果字符串 `s` 有效而必须添加的最少括号数*。

**示例 1：**

```C++
输入：s = "())"
输出：1
```

**示例 2：**

```C++
输入：s = "((("
输出：3 
```

**提示：**

- `1 <= s.length <= 1000`
- `s` 只包含 `'('` 和 `')'` 字符。

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    int minAddToMakeValid(string s) {
        //用栈
        // if (s.empty()) return 1;
        // stack<char> brackets;
        // int num = 0;
        // for (int i = 0; i < s.size(); i++) {
        //     if (s[i] == '(') brackets.push(s[i]);
        //     else {
        //         if (!brackets.empty() && brackets.top() == '(') {
        //             brackets.pop();
        //         }
        //         //')'需要添加的括号数量
        //         else  num++;
        //     }
        // }
        // return num + brackets.size();
        //计数
        int LBrackets = 0;
        int num = 0;
        for (auto c : s) {
            if (c == '(') LBrackets++;
            else if (c == ')' && LBrackets != 0) LBrackets--;
            else num++; 
        }
        return num + LBrackets;
    }
};
```

---

### 1624.[两个相同字符之间的最长子字符串](https://leetcode.cn/problems/largest-substring-between-two-equal-characters/description/)

**题目：[使括号有效的最少添加](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/description/)**

给你一个字符串 `s`，请你返回 **两个相同字符之间的最长子字符串的长度** *，*计算长度时不含这两个字符。如果不存在这样的子字符串，返回 `-1` 。

**子字符串** 是字符串中的一个连续字符序列。

**示例 1：**

```C++
输入：s = "aa"
输出：0
解释：最优的子字符串是两个 'a' 之间的空子字符串。
```

**示例 2：**

```C++
输入：s = "abca"
输出：2
解释：最优的子字符串是 "bc" 。
```

**示例 3：**

```C++
输入：s = "cbzxy"
输出：-1
解释：s 中不存在出现出现两次的字符，所以返回 -1 。
```

**示例 4：**

```C++
输入：s = "cabbac"
输出：4
解释：最优的子字符串是 "abba" ，其他的非最优解包括 "bb" 和 "" 。
```

**提示：**

- `1 <= s.length <= 300`
- `s` 只含小写英文字母

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
       /*  int k;       
        int maxlen = -1;
        int curlen;
        int len = s.length();
        for (int i = 0;i < len; i++) {   
            k = -1;
            for (int j = i + 1; j < len; j++) {
                if (s[j] == s[i]) k = j;
            }
            if (k != -1) curlen = k - i - 1;
            if (curlen > maxlen) maxlen = curlen;
        }
        return maxlen; */
        
        vector<int> firstIndex(26, -1);
        int maxLength = -1;
        for (int i = 0; i < s.size(); i++) {
            if (firstIndex[s[i] - 'a'] < 0) {
                firstIndex[s[i] - 'a'] = i;
            } else {
                maxLength = max(maxLength, i - firstIndex[s[i] - 'a'] - 1);
            }
        }
        return maxLength;

    }
};
```

----

### 1694.[重新格式化电话号码](https://leetcode.cn/problems/reformat-phone-number/description/)

**题目：**

给你一个字符串形式的电话号码 `number` 。`number` 由数字、空格 `' '`、和破折号 `'-'` 组成。

请你按下述方式重新格式化电话号码。

- 首先，**删除** 所有的空格和破折号。
- 其次，将数组从左到右每 3 个一组分块，直到 剩下 4 个或更少数字。剩下的数字将按下述规定再分块：
  - 2 个数字：单个含 2 个数字的块。
  - 3 个数字：单个含 3 个数字的块。
  - 4 个数字：两个分别含 2 个数字的块。

最后用破折号将这些块连接起来。注意，重新格式化过程中 **不应该** 生成仅含 1 个数字的块，并且 **最多** 生成两个含 2 个数字的块。

返回格式化后的电话号码。

**示例 1：**

```C++
输入：number = "1-23-45 6"
输出："123-456"
解释：数字是 "123456"
步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
步骤 2：剩下 3 个数字，将它们放入单个含 3 个数字的块。第 2 个块是 "456" 。
连接这些块后得到 "123-456" 。
```

**示例 2：**

```C++
输入：number = "123 4-567"
输出："123-45-67"
解释：数字是 "1234567".
步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
步骤 2：剩下 4 个数字，所以将它们分成两个含 2 个数字的块。这 2 块分别是 "45" 和 "67" 。
连接这些块后得到 "123-45-67" 。
```

**示例 3：**

```C++
输入：number = "123 4-5678"
输出："123-456-78"
解释：数字是 "12345678" 。
步骤 1：第 1 个块 "123" 。
步骤 2：第 2 个块 "456" 。
步骤 3：剩下 2 个数字，将它们放入单个含 2 个数字的块。第 3 个块是 "78" 。
连接这些块后得到 "123-456-78" 。
```

**示例 4：**

```C++
输入：number = "12"
输出："12"
```

**示例 5：**

```C++
输入：number = "--17-5 229 35-39475 "
输出："175-229-353-94-75"
```

**提示：**

- `2 <= number.length <= 100`
- `number` 由数字和字符 `'-'` 及 `' '` 组成。
- `number` 中至少含 **2** 个数字。

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    string reformatNumber(string number) {
        string s;
        for (auto c : number) {
            if (c != ' ' && c != '-') {
               s += c;
            }
        }
        int n = s.size();
        int pt = 0;
        string res; 
        while (n) {
            if (n > 4) {
                res += s.substr(pt, 3) + "-";
                pt += 3;
                n -= 3;
            }
            else {
                if (n == 4) {
                    res += s.substr(pt, 2) + "-" + s.substr(pt + 2, 2);
                }
                else {
                    res += s.substr(pt, n);
                }
                break;
            }
        }
        return res;
    }
};
```

---

### 1784.[检查二进制字符串字段](https://leetcode.cn/problems/check-if-binary-string-has-at-most-one-segment-of-ones/description/)

**题目：**

给你一个二进制字符串 `s` ，该字符串 **不含前导零** 。

如果 `s` 包含 **零个或一个由连续的 `'1'` 组成的字段** ，返回 `true` 。否则，返回 `false` 。

如果 `s` 中 **由连续若干个 `'1'` 组成的字段** 数量不超过 `1`，返回 `true` 。否则，返回 `false` 。

**示例 1：**

```C++
输入：s = "1001"
输出：false
解释：由连续若干个 '1' 组成的字段数量为 2，返回 false
```

**示例 2：**

```
输入：s = "110"
输出：true
```

**提示：**

- `1 <= s.length <= 100`
- `s[i]` 为 `'0'` 或 `'1'`
- `s[0]` 为 `'1'`

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int i = 0;
        while (s[i] != '0' && i < n) i++;
        if (i == n - 1) return true;
        else {
            for (; i < n; i++) {
                if (s[i] == '1') return false;
            }
        }
        return true;
        //return s.find("01") == string::npos;
    }
};
```

---

## 栈与队列 

### 20.[有效的括号](https://leetcode.cn/problems/valid-parentheses/description/)

**题目：**

给定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s` ，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。

**示例 1：**

```C++
输入：s = "()"
输出：true
```

**示例 2：**

```C++
输入：s = "()[]{}"
输出：true
```

**示例 3：**

```C++
输入：s = "(]"
输出：false
```

**示例 4：**

```C++
输入：s = "([)]"
输出：false
```

**示例 5：**

```
输入：s = "{[]}"
输出：true
```

**提示：**

- `1 <= s.length <= 104`
- `s` 仅由括号 `'()[]{}'` 组成

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char> op;
        
        for (int i = 0 ; i < s.size(); i++) {
            if (s[i] == '(') op.push(')');
            else if (s[i] == '{') op.push('}');
            else if (s[i] == '[') op.push(']');
            else if (!op.empty() && s[i] == op.top()) {
                op.pop();
            }
            else return false;
        }
        return op.empty();

    }
};
```

---

### 150.[逆波兰表达式求值](https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/)

**题目：**

根据[ 逆波兰表示法](https://baike.baidu.com/item/逆波兰式/128437)，求表达式的值。

有效的算符包括 `+`、`-`、`*`、`/` 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

**注意** 两个整数之间的除法只保留整数部分。

可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

**示例 1：**

```C++
输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
```

**示例 2：**

```C++
输入：tokens = ["4","13","5","/","+"]
输出：6
解释：该算式转化为常见的中缀算术表达式为：(4 + (13 / 5)) = 6
```

**示例 3：**

```C++
输入：tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
输出：22
解释：该算式转化为常见的中缀算术表达式为：
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
```

**提示：**

- `1 <= tokens.length <= 104`
- `tokens[i]` 是一个算符（`"+"`、`"-"`、`"*"` 或 `"/"`），或是在范围 `[-200, 200]` 内的一个整数

**逆波兰表达式：**

逆波兰表达式是一种后缀表达式，所谓后缀就是指算符写在后面。

- 平常使用的算式则是一种中缀表达式，如 `( 1 + 2 ) * ( 3 + 4 )` 。
- 该算式的逆波兰表达式写法为 `( ( 1 2 + ) ( 3 4 + ) * )` 。

逆波兰表达式主要有以下两个优点：

- 去掉括号后表达式无歧义，上式即便写成 `1 2 + 3 4 + * `也可以依据次序计算出正确结果。
- 适合用栈操作运算：遇到数字则入栈；遇到算符则取出栈顶两个数字进行计算，并将结果压入栈中

**思路：**

**C++代码实现：**

```C++
```

---

### 232.[用栈实现队列](https://leetcode.cn/problems/implement-queue-using-stacks/description/)

**题目：**

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（`push`、`pop`、`peek`、`empty`）：

实现 `MyQueue` 类：

- `void push(int x)` 将元素 x 推到队列的末尾
- `int pop()` 从队列的开头移除并返回元素
- `int peek()` 返回队列开头的元素
- `boolean empty()` 如果队列为空，返回 `true` ；否则，返回 `false`

**说明：**

- 你 **只能** 使用标准的栈操作 —— 也就是只有 `push to top`, `peek/pop from top`, `size`, 和 `is empty` 操作是合法的。
- 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

**示例 1：**

```C++
输入：
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 1, 1, false]

解释：
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
```

**提示：**

- `1 <= x <= 9`
- 最多调用 `100` 次 `push`、`pop`、`peek` 和 `empty`
- 假设所有操作都是有效的 （例如，一个空的队列不会调用 `pop` 或者 `peek` 操作）

**进阶：**

- 你能否实现每个操作均摊时间复杂度为 `O(1)` 的队列？换句话说，执行 `n` 个操作的总时间复杂度为 `O(n)` ，即使其中一个操作可能花费较长时间。

**思路：**

**C++代码实现：**

```C++
class MyQueue {
public:
    stack<int> In;
    stack<int> Out;

    MyQueue() {
       
    }
    
    void push(int x) {
        In.push(x);
    }
    
    int pop() {
        if (Out.empty()) {
            while (!In.empty()) {
                Out.push(In.top());
                In.pop();
            }
        }
        int res = Out.top();
        Out.pop();
        return res;
    }
    
    int peek() {
        if (Out.empty()) {
            while (!In.empty()) {
                Out.push(In.top());
                In.pop();
            }
        }
        return Out.top();
    }
    
    bool empty() {
        return In.empty() && Out.empty();
    }
};
```

----

### 225. [用队列实现栈](https://leetcode.cn/problems/implement-stack-using-queues/description/)

**题目：**

请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（`push`、`top`、`pop` 和 `empty`）。

实现 `MyStack` 类：

- `void push(int x)` 将元素 x 压入栈顶。
- `int pop()` 移除并返回栈顶元素。
- `int top()` 返回栈顶元素。
- `boolean empty()` 如果栈是空的，返回 `true` ；否则，返回 `false` 。

**注意：**

- 你只能使用队列的基本操作 —— 也就是 `push to back`、`peek/pop from front`、`size` 和 `is empty` 这些操作。
- 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。

**示例：**

```C++
输入：
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 2, 2, false]

解释：
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // 返回 2
myStack.pop(); // 返回 2
myStack.empty(); // 返回 False
```

**提示：**

- `1 <= x <= 9`
- 最多调用`100` 次 `push`、`pop`、`top` 和 `empty`
- 每次调用 `pop` 和 `top` 都保证栈不为空

**进阶：**你能否仅用一个队列来实现栈。

**思路：**

**C++代码实现：**

```C++
class MyStack {
public:
    queue<int> que1;
    queue<int> que2; 

    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        size--;
        while (size--) { // 将que1 导入que2，但要留下最后一个元素
            que2.push(que1.front());
            que1.pop();
        }

        int result = que1.front(); // 留下的最后一个元素就是要返回的值
        que1.pop();
        que1 = que2;            // 再将que2赋值给que1
        while (!que2.empty()) { // 清空que2
            que2.pop();
        }
        return result;
    }
    
    int top() {
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
};

/*
//用一个队列的方法
class MyStack {
public:
    queue<int> que;

    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int size = que.size();
        size--;
        while (size--) { // 将最后一个元素前面的元素都添加都前面
            que.push(que.front());
            que.pop();
        }

        int result = que.front(); // 留下的最后一个元素就是要返回的值
        que.pop();
        return result;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
};
*/
```

---

### 239.[滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/description/)

**题目：**

给你一个整数数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 `k` 个数字。滑动窗口每次只向右移动一位。

返回 *滑动窗口中的最大值* 。

**示例 1：**

```C++
输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
```

**示例 2：**

```C++
输入：nums = [1], k = 1
输出：[1]
```

**提示：**

- `1 <= nums.length <= 105`
- `-104 <= nums[i] <= 104`
- `1 <= k <= nums.length`

**思路：**

使用单调队列。

设计单调队列的时候，pop，和push操作要保持如下规则：

1. pop(value)：如果窗口移除的元素value等于单调队列的出口元素，那么队列弹出元素，否则不用任何操作
2. push(value)：如果push的元素value大于入口元素的数值，那么就将队列入口的元素弹出，直到push元素的数值小于等于队列入口元素的数值为止

保持如上规则，每次窗口移动的时候，只要问que.front()就可以返回当前窗口的最大值。

**C++代码实现：**

```C++
class Solution {
private:
    class MyQueue { //单调队列（从大到小）
    public:
        deque<int> que; // 使用deque来实现单调队列
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        // 同时pop之前判断队列当前是否为空。
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }
        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);

        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0; i < k; i++) { // 先将前k的元素放进队列
            que.push(nums[i]);
        }
        result.push_back(que.front()); // result 记录前k的元素的最大值
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]); // 滑动窗口移除最前面元素
            que.push(nums[i]); // 滑动窗口前加入最后面的元素
            result.push_back(que.front()); // 记录对应的最大值
        }
        return result;
    }
};
```

---

### 347.[前 K 个高频元素](https://leetcode.cn/problems/top-k-frequent-elements/description/)

**题目：**

给你一个整数数组 `nums` 和一个整数 `k` ，请你返回其中出现频率前 `k` 高的元素。你可以按 **任意顺序** 返回答案。

**示例 1:**

```C++
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
```

**示例 2:**

```C++
输入: nums = [1], k = 1
输出: [1]
```

**提示：**

- `1 <= nums.length <= 105`
- `k` 的取值范围是 `[1, 数组中不相同的元素的个数]`
- 题目数据保证答案唯一，换句话说，数组中前 `k` 个高频元素的集合是唯一的

**进阶：**你所设计算法的时间复杂度 **必须** 优于 `O(n log n)` ，其中 `n` 是数组大小。

**思路：**

**C++代码实现：**

```C++
```

---

### 1047.[删除字符串中的所有相邻重复项](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/)

**题目：**

给出由小写字母组成的字符串 `S`，**重复项删除操作**会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

**示例：**

```C++
输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
```

**提示：**

1. `1 <= S.length <= 20000`
2. `S` 仅由小写英文字母组成。

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> A;
        for (char c : s) {
            if (!A.empty()) {
                if (c == A.top()) {
                    A.pop();
                } 
                else {
                    A.push(c);
                }
            }
            else {
                A.push(c);
            }
        }
        s = ""; 
        while (!A.empty()) {
            s += A.top();
            A.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
```

---

## 二叉树

## 回溯算法

## 贪心算法

## 动态规划

## 单调栈

## 其他

### 672.[灯泡开关 Ⅱ](https://leetcode.cn/problems/bulb-switcher-ii/description/)

**题目：**

房间中有 `n` 只已经打开的灯泡，编号从 `1` 到 `n` 。墙上挂着 **4 个开关** 。

这 4 个开关各自都具有不同的功能，其中：

- **开关 1 ：**反转当前所有灯的状态（即开变为关，关变为开）
- **开关 2 ：**反转编号为偶数的灯的状态（即 `2, 4, ...`）
- **开关 3 ：**反转编号为奇数的灯的状态（即 `1, 3, ...`）
- **开关 4 ：**反转编号为 `j = 3k + 1` 的灯的状态，其中 `k = 0, 1, 2, ...`（即 `1, 4, 7, 10, ...`）

你必须 **恰好** 按压开关 `presses` 次。每次按压，你都需要从 4 个开关中选出一个来执行按压操作。

给你两个整数 `n` 和 `presses` ，执行完所有按压之后，返回 **不同可能状态** 的数量。

**示例 1：**

```C++
输入：n = 1, presses = 1
输出：2
解释：状态可以是：
- 按压开关 1 ，[关]
- 按压开关 2 ，[开]
```

**示例 2：**

```C++
输入：n = 2, presses = 1
输出：3
解释：状态可以是：
- 按压开关 1 ，[关, 关]
- 按压开关 2 ，[开, 关]
- 按压开关 3 ，[关, 开]
```

**示例 3：**

```C++
输入：n = 3, presses = 1
输出：4
解释：状态可以是：
- 按压开关 1 ，[关, 关, 关]
- 按压开关 2 ，[关, 开, 关]
- 按压开关 3 ，[开, 关, 开]
- 按压开关 4 ，[关, 开, 开]
```

**提示：**

- `1 <= n <= 1000`
- `0 <= presses <= 1000`

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    int flipLights(int n, int presses) {
         //不按开关
        if (presses == 0) {
            return 1;
        }
        //特殊情况处理
        if (n == 1) {
            return 2;
        } else if (n == 2) {
            //特殊情况
            return presses == 1 ? 3 : 4;
        } else {
            //n >= 3
            return presses == 1 ? 4 : presses == 2 ? 7 : 8;
        }
    }
};
```

---

### 1652.[拆炸弹](https://leetcode.cn/problems/defuse-the-bomb/description/)

**题目：**

你有一个炸弹需要拆除，时间紧迫！你的情报员会给你一个长度为 `n` 的 **循环** 数组 `code` 以及一个密钥 `k` 。

为了获得正确的密码，你需要替换掉每一个数字。所有数字会 **同时** 被替换。

- 如果 `k > 0` ，将第 `i` 个数字用 **接下来** `k` 个数字之和替换。
- 如果 `k < 0` ，将第 `i` 个数字用 **之前** `k` 个数字之和替换。
- 如果 `k == 0` ，将第 `i` 个数字用 `0` 替换。

由于 `code` 是循环的， `code[n-1]` 下一个元素是 `code[0]` ，且 `code[0]` 前一个元素是 `code[n-1]` 。

给你 **循环** 数组 `code` 和整数密钥 `k` ，请你返回解密后的结果来拆除炸弹！

**示例 1：**

```c++
输入：code = [5,7,1,4], k = 3
输出：[12,10,16,13]
解释：每个数字都被接下来 3 个数字之和替换。解密后的密码为 [7+1+4, 1+4+5, 4+5+7, 5+7+1]。注意到数组是循环连接的。
```

**示例 2：**

```c++
输入：code = [1,2,3,4], k = 0
输出：[0,0,0,0]
解释：当 k 为 0 时，所有数字都被 0 替换。
```

**示例 3：**

```C++
输入：code = [2,4,9,3], k = -2
输出：[12,5,6,13]
解释：解密后的密码为 [3+9, 2+3, 4+2, 9+4] 。注意到数组是循环连接的。如果 k 是负数，那么和为 之前 的数字。
```

**提示：**

- `n == code.length`
- `1 <= n <= 100`
- `1 <= code[i] <= 100`
- `-(n - 1) <= k <= n - 1`

**思路：**

**C++代码实现：**

```C++
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        //滑动窗口
        int n = code.size();
        vector<int> A(n, 0);
        if(k == 0) return A;
        int sum = 0;
        for(int i = 0; i < abs(k); i++) 
            sum += code[i]; 
        
        for(int i = 0; i < n; i++) {
            if(k > 0) {
                A[(i - 1 + n) % n] = sum;
            } else {
                A[(i - k + n) % n] = sum;
            }
            sum -= code[i];
            sum += code[(i + abs(k)) % n];
        }
        return A;
    }
};
```

---





