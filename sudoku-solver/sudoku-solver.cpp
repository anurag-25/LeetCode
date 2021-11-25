class Solution {
    bool isSafe (vector<vector<char>>& board, int row, int col, char c) {
        int quadrantRow = row/3*3, quadrantCol = col/3*3;
        for (int i=0; i<9; i++) {
            if (board[i][col] == c || board[row][i] ==c || 
               board[quadrantRow+ i/3][quadrantCol+ i%3] ==c) return false;
        }
        return true;
    }
    
public:
    bool solve (vector<vector<char>>& board, int row, int col) {
        for (int i=row; i<9; i++) {
            for (int j=col; j<9; j++) {
                if (board[i][j]=='.') {
                    for (char c = '1'; c<='9'; c++){
                        if (isSafe(board, i, j, c) ) {
                            board[i][j] = c;
                            if (solve (board, row, col+1) ) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
            col=0;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve (board, 0, 0);
    }
};