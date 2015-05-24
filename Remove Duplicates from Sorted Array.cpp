/*
 Problem:    Remove Duplicates from Sorted Array
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_26
 Notes:
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 Do not allocate extra space for another array, you must do this in place with constant memory.
 For example,
 Given input array A = [1,1,2],
 Your function should return length = 2, and A is now [1,2].
 Solution: Update 7/16/2013: Let j start from 0 for better understanding.
 */

解一：
复杂度：Ｏ（ｎ），但是每次发现前后2个元素相同，都需要把整个数组后面部分全部往前移动一个单位，会导致超时
   int removeDuplicates(int A[], int n) {
        for(int i = 0; i < n-1; ) {
            if(A[i] == A[i+1]) {
                for(int j = i+1; j < n-1; j++)
                    A[j] = A[j+1];
                n--;
            } else {
                i++;
            }
        }
        return n;
    }


解法二：
思路great！！！ : 2个下标，i 标记 遍历的下标， index标记保存不同元素数组的下标
具体做法是两两比较原数组相邻元素，如果遇到不相等的，则把第二个数赋值给A[index].如果相等，则i往前走一个即可
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int index = 1;
        if(n == 0) return 0;
        for(int i = 1; i < n; i++ ){
            if(A[i] != A[i-1]) {
                A[index] = A[i];
                index++;
            }
        }
        return index;
    }
};


上面的解法是针对有序数组，如果是无序数组，应该如何解答？
        
思路：
（1）如果不允许申请额外空间，则可以先对数组进行排序，为了提高效率一般考虑使用快速排序，然后再参照上面有序数组进行操作；
（2）如果允许申请空间，则只需创建一个HashSet，遍历一次数组，通过contanins()方法进行判断就能得到结果。
（1）和（2）所对应代码如下所示（注：针对本文所示的题目，如果用下面代码进行OJ，（1）会超时，（2）会产生额外空间）：
不可以申请额外空间：

可以申请额外空间：（其中，HashSet的contains()方法是用来过滤重复元素的）
java：
public static int removeDuplicates(int[] A) {
    int len = A.length;
    HashSet<integer> set = new HashSet<integer>();
    for (int i = 0; i < len; i++) {
        if (set.size() == 0) {
            set.add(A[i]);
        }
        if (!set.contains(A[i])) {
            set.add(A[i]);
        }
    }
    return set.size();
}

