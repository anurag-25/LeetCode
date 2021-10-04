class Solution {
private:
    int m=0, n=0;
    int solve (vector<vector<int>>& matrix, vector <vector<int>> &dp, int i, int j) {
        // if (i<0 || i>=m || j<0 || j>=n ) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int mx = 0;
        if (i-1>=0 && matrix[i-1][j]>matrix[i][j]) mx = max (mx, solve (matrix, dp, i-1, j) );
        if (i+1<=m-1 && matrix[i+1][j]>matrix[i][j]) mx = max (mx, solve (matrix, dp, i+1, j) ); 
        if (j-1>=0 && matrix[i][j-1]>matrix[i][j]) mx = max (mx, solve (matrix, dp, i, j-1) );
        if (j+1<=n-1 && matrix[i][j+1]>matrix[i][j]) mx = max (mx, solve (matrix, dp, i, j+1) ); 
        return dp[i][j] = mx+1;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        vector <vector<int>> dp (m, vector <int> (n, -1));
        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (dp[i][j] == -1) {
                     ans = max (ans, solve(matrix, dp, i, j) );
                }
            }
        }
        return ans;
    }
};