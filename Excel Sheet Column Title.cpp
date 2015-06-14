/*
Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    solution:  just a little trick to handle corner case 26
*/

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        if (n <= 0) {
            return res;
        }
        while (n != 0) {
            res = (char)((n-1)%26 + 'A') + res;
            n = (n-1)/26;
        }
        return res;
    }
};
