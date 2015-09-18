/*
Add Digits

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
Follow up:
Could you do it without any loop/recursion in O(1) runtime?
*/

/**********尾递归**************/
class Solution1 {
public:
    int addDigits(int num) {
        if (num/10 == 0) {
            return num;
        }
        int sum = 0;
        while (num/10) {
            sum += num%10;
            num = num/10;
        }
        sum += num;
        return addDigits(sum);
    }
};

/**********尾递归-->非递归**************/
class Solution2 {
public:
    int addDigits(int num) {
        while(num/10) {
            int sum = 0;
            while (num/10) {
                sum += num%10;
                num = num/10;
            }
            sum += num;
            
            num = sum;
        }
        return num;
    }
};

/*********同余数公式：dr(n) = 1 + (n - 1) % 9 **********/
class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};


