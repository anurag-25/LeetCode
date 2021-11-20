class Solution {
    int m,n;
    vector<int> dir = {0,1,0,-1,0};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size(), n=mat[0].size();
        queue<pair<int, int>> q;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (mat[i][j]==0) q.push({i,j});
                else mat[i][j] = -1;
            }
        }
        
        int cx, cy, nx, ny;
        while (!q.empty()) {
            cx = q.front().first, cy = q.front().second;
            q.pop();
            for (int i=0; i<4; i++) {
                nx = cx + dir[i];
                ny = cy + dir[i+1];
                if (nx<0||nx>=m||ny<0||ny>=n || mat[nx][ny]!=-1) continue;
                mat[nx][ny] = mat[cx][cy]+1;
                q.push ({nx, ny});
            }
        }
        return mat;
    }
};