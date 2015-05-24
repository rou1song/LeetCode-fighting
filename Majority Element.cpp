/*
 Problem:    Majority Element
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/majority-element/
 Notes:
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 You may assume that the array is non-empty and the majority element always exist in the array.
 Solution: 1. Runtime: O(n) — Moore voting algorithm: We maintain a current candidate and a counter initialized to 0. As we iterate the array, we look at the current element x:
 If the counter is 0, we set the current candidate to x and the counter to 1.
 If the counter is not 0, we increment or decrement the counter based on whether x is the current candidate.
 After one pass, the current candidate is the majority element. Runtime complexity = O(n).
 2. Runtime: O(n) — Bit manipulation: We would need 32 iterations, each calculating the number of 1's for the ith bit of all n numbers. Since a majority must exist, therefore, either count of 1's > count of 0's or vice versa (but can never be equal). The majority number’s ith bit must be the one bit that has the greater count.
 */
 
 解法一：
排序，然后取中间值
class Solution {
public:
    int majorityElement(vector<int> &num) {
        sort(num.begin(),num.end());
        return num[num.size() / 2];
    }
};

解法二：（hashmap ）
开辟一个数组，记录元素出现次数，取出大于n/2的元素
缺点：开辟空间比较大，

解法四：
（快排），每次找pivot，找到A[n/2]即返回



解法三（标准解法）：
抵销法，但不是真的删除数组的元素，而是采用变量times计数方式
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int i,times = 0;
        int candidate;
        for(i = 0; i < num.size(); i++) {
            if(times == 0) {
                candidate = num[i];
                times = 1;
            }
            else {
                if(num[i] == candidate)
                    times++;
                else
                    times--;
            }
        }
        return candidate;
    }
};
