class Solution {
    int m, n;
public:
    bool helper (vector<vector<char>>& board, string word, int i, int x, int y) {
        if (x<0 || x>=m || y<0 || y>=n) return false;
        bool ans = false;
        if (word[i] == board[x][y]) {
            if (i==word.size()-1) return true;
            char temp = board[x][y];
            board[x][y] = '*';
            ans = helper (board, word, i+1, x-1, y) || helper (board, word, i+1, x+1, y) || 
                helper (board, word, i+1, x, y-1) || helper (board, word, i+1, x, y+1);
            board[x][y]= temp;
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j]==word[0]) {
                    if (helper (board, word, 0, i, j) ) return true;
                }
            }
        }
        return false;
    }
};