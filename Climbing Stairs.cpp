/*
Difficulty: medium
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

思路：
采用动态规划来解题，动态规划最重要的是对f（n）的定义是什么：
这里f（n）表示：到达n阶台阶的方法数
它可以有2种方式到达n阶，
     1、n-1阶，走1 step。 f（n-1）
     2、n-2阶，1次走2 step或 2次走1 step ，但2次走一步归在f（n-1）里面了
     所以f（n） = f（n-1）+f（n-2）；
如此可得它是一个斐波那契数列。

或者另一种思想更好： f（n）是前面走好之后通过2种方式得到的，1.最后一步走1 step，  2.最后一步走2step 

斐波那契数列的不同解法：
一个特别好的Fibonacci数列 参考链接：http://www.cnblogs.com/hlxs/archive/2011/07/15/2107389.html
&& http://blog.csdn.net/niuox/article/details/7252674

解法一：
递归方式：
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 0) return -1;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n > 2)
            return climbStairs(n-1) +  climbStairs(n-2);
    }
};
时间复杂度：O（指数级复杂度），空间O(1)
运行超时！！！


解法二：
数组迭代： 时间复杂度：O（n），空间O(n)
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int A[n];
        A[0] = 1;
        A[1] = 2;
        for(int i = 2; i < n; i++ ){
            A[i] = A[i-1] + A[i-2];
        }
        return A[n-1];
    }
};

解法三： 最优解
改进的数组迭代，不使用数组了。
采用a,b,c 三个临时变量迭代来获得f（n）最终的值，但是这样不能得到斐波那契序列。
时间：O（n） 空间：O（1）

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int a = 1,b = 2,c;
        for(int i = 2; i < n; i++ ){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

解法四：
矩阵解法：
时间：O（logn） 空间O(1)
