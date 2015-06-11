/*
 Problem:    Divide Two Integers
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/divide-two-integers/
 Notes:
 Divide two integers without using multiplication, division and mod operator.
 Solution: Use << operator.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans = 0;
        int flag = 1;
        
        if (divisor == 0) {
            return INT_MAX;
        }
        
        if (dividend == 0) {
            return 0;
        }
        
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            flag = -1;
        }
        
        long long dividend1 = abs((long long) dividend);
        long long divisor1 = abs((long long) divisor);
        
        while (dividend1 >= divisor1) {
            long long m = 1;
            long long d = divisor1;
            while (dividend1 >= (d<<1)) {
                d = d << 1;
                m = m << 1;
            }
            ans += m;
            dividend1 -= d;
        }
        
        ans = flag * ans;
        
        if (ans > INT_MAX) {
            return INT_MAX;
        } else {
            return ans;
        }
    }
};
