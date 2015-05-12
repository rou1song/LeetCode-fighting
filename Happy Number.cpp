/*
Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares of its digits, 
and repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
Example: 19 is a happy number
  12 + 92 = 82
  82 + 22 = 68
  62 + 82 = 100
  12 + 02 + 02 = 1
*/

//核心思路： 判断后面计算的sum值之前是否出现过，否则继续计算，出现过若sum == 1， 则true；否则false； 
//定义全局的set！ 想想为什么是set而不是vector！
class Solution1 {
public:
    unordered_set<int> s;
    bool isHappy(int n) {
        int i;
        int sum = 0;
        while(n != 0) {
            i = n%10;
            sum += i*i;
            n = n/10;
        }
        if(sum == 1)  return true;
        if(s.find(sum) == s.end()) s.insert(sum);
        else return false;
        return isHappy(sum);
    }
};

//之前做过的 list cycle detection。 这样不需要set的空间，但会有重复计算，时间花更多
class Solution2 {
public:
    bool isHappy(int n) {
        int slow = nxt(n), fast = nxt(nxt(n));
        while (slow != 1 && slow != fast) {
            slow = nxt(slow);
            fast = nxt(fast);
            fast = nxt(fast);
        }
        if(slow == 1) return true;
        else return false;
    }
private:
    int nxt(int num) {
        int sum = 0;
        while (num) {
            sum += (num % 10) * (num % 10);
            num /= 10;
        }
        return sum;
    }
};
