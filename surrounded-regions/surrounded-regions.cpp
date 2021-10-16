class Solution {
    int m, n;
public:
    void dfs (vector<vector<char>>& board, int i, int j) {
        board[i][j] ='*';
        if (i-1>=0 && board[i-1][j] == 'O') dfs (board, i-1, j);
        if (i+1<m && board[i+1][j] == 'O') dfs (board, i+1, j); 
        if (j-1>=0 && board[i][j-1] == 'O') dfs (board, i, j-1);
        if (j+1<n && board[i][j+1] == 'O') dfs (board, i, j+1);  
    }
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for (int col = 0; col <=n-1; col++) {
            if (board[0][col] == 'O') dfs (board, 0, col);
            if (board[m-1][col] == 'O') dfs (board, m-1, col);
        }
        for (int row = 0; row<=m-1; row++) {
            if (board[row][0] =='O') dfs (board, row, 0);
            if (board[row][n-1] =='O') dfs (board, row, n-1);
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '*') board[i][j] = 'O';
            }
        }
        return;
    }
};