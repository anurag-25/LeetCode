class Solution {
private:
    vector<int> parent;
public:
    int find (int i) {
        if (parent[i] == -1) return i;
        return parent[i] = find(parent[i]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize (n, -1);
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                // if (i==j) continue;
                if (isConnected[i][j]) {
                    int p1 = find (i);
                    int p2 = find (j);
                    if (p1 != p2) parent[p2] = p1;
                }
            }
        }
        int ans =0;
        for (int i=0; i<n; i++) if (parent[i]==-1) ans++;
        return ans;
    }
};