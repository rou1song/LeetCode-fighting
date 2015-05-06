/*
 Problem:    Pow(x, n)
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_50
 Notes:
 Implement pow(x, n).
 
 Solution: recursion.
 */
 
 //一定要注意INT_MIN 的考虑，单纯写成 if(n < 0) return 1.0/myPow(x, -n) 会再INT_MIN这个用例死循环。
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) {
            if(n == INT_MIN)
                return 1.0/ (myPow(x, INT_MAX) * x);
            else
                return 1.0/myPow(x, -n);
        }
        return n%2 == 0? myPow(x*x, n/2) : x*myPow(x*x, (n-1)/2);
    }
};
