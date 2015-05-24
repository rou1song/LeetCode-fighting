/*
 Problem:    Set Matrix Zeroes
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_73
 Notes:
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 Follow up:
 Did you use extra space?
 A straight forward solution using O(mn) space is probably a bad idea.
 A simple improvement uses O(m + n) space, but still not the best solution.
 Could you devise a constant space solution?
 Solution: Use first row and column as auxiliary spaces instead of newly allocating ones.
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        if(row == 0) return ;
       
        bool firstrow = false;          //判断第一行、第一列是否有0
        bool firstcol = false;
       
        for(int i = 0; i < row; i++)
            if(matrix[i][0] == 0) {
                firstcol = true;
                break;
            }
   
        for(int j = 0; j < col; j++)
            if(matrix[0][j] == 0) {
                firstrow = true;
                break;
            }
//行列下标都从1开始，把该元素所在行、列都的首位元素都置为0       
        for(int i = 1; i < row; i++)
            for(int j = 1; j < col; j++)
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
//给每个元素赋值（比发现一行为0，给每一行赋0值要高效）          
        for(int i = 1; i < row; ++i) 
            for(int j = 1; j < col; ++j) 
                if(matrix[i][0] == 0 || matrix[0][j] == 0) 
                    matrix[i][j] = 0;
    
        if(firstrow)
            for(int j = 0; j < col; j++)
                matrix[0][j] = 0;
               
        if(firstcol)
            for(int i = 0; i < row; i++)
                matrix[i][0] = 0;
    }
};
