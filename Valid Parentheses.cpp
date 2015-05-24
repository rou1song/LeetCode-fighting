/*
 Problem:    Valid Parentheses
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_20
 Notes:
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 Solution: stack.
 */

学习到的知识点：
1. 栈的操作：
新建字符型栈：stack<char> st;
把数据s[i]压栈：st.push(s[i]);
     出栈：st.pop();
获得栈顶数据：st.top()
判断栈空：st.empty()
2. 犯的错误： if（s[i] = ')'） ...   应该是 ==  
3.for（int i = 0; i <.. ; i++） 其中 int i = 0 在for循环里面比较好，作用范围用得好，出错马上能查出来。 一般这么写，如果程序后面要用到i的值，比如atoi那道题，那就把i放外面。

解法：
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty())
                    return false;
                   
                char c = st.top();
                if (( s[i] == ')' && c != '(' ) || ( s[i] == '}' && c != '{' ) || ( s[i] == ']' && c != '[' ))
                    return false;
                st.pop();
            }
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};
