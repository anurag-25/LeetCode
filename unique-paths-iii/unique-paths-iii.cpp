class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1, 0},{0,1},{0,-1}}; 
    int m, n, ans;
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), ans =0;
        int sx=0, sy=0, visit=0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) sx = i, sy =j;
                else if (grid[i][j] == 0) visit++;
            }
        }
        dfs (grid, sx, sy, visit);
        return ans;
    }
    void dfs (vector<vector<int>>& grid, int x, int y, int visit) {
        if (x<0 || x>=m || y<0 || y>=n || grid[x][y]==-1) return;
        if (grid[x][y] == 2) {
            if (visit==-1) ans++;
            return;
        }
        grid[x][y] = -1;
        for (auto d: dir) {
            dfs (grid, x+d[0], y+d[1], visit-1);
        }
        grid[x][y] = 0;
    }
};