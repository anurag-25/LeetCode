class Solution {
    vector<vector<string>> ans;
    vector<bool> col, mainD, offD;
public:
    bool isSafe (int i, int j, int n) {
        return col[j] && mainD[i-j+n-1] && offD[i+j];
    }
    
    void solve (int n, vector<string> &board, int row) {
        if (row == n) {
            ans.push_back (board);
            return;
        }
        for (int i=0; i<n; i++) {
            if (isSafe(row, i, n)) {
                board[row][i] = 'Q';
                col[i] = false, mainD[row-i+n-1] = false, offD[row+i] = false;

                solve (n, board, row+1);

                col[i] = true, mainD[row-i+n-1] = true, offD[row+i] = true;
                board[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        col.resize(n, true), offD.resize(2*n-1, true), mainD.resize(2*n-1, true);
        
        string s (n, '.');
        vector<string> board (n, s);
        
        solve (n, board, 0);
        return ans;
    }
};