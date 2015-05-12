class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            unordered_set<char> srow, scol, sbox;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.' && srow.find(board[i][j]) != srow.end())
                    return false;
                if(board[i][j] != '.')
                    srow.insert(board[i][j]);

                if(board[j][i] != '.' && scol.find(board[j][i]) != scol.end())
                    return false;
                if(board[j][i] != '.')
                    scol.insert(board[j][i]);

                int row = (i/3)*3;
                int col = (i%3)*3;
                if(board[row+j/3][col+j%3] != '.' && sbox.find(board[row+j/3][col+j%3]) != sbox.end()) 
                    return false;
                if(board[row+j/3][col+j%3] != '.')
                    sbox.insert(board[row+j/3][col+j%3]);
            }
        }
        return true;
    }
};
