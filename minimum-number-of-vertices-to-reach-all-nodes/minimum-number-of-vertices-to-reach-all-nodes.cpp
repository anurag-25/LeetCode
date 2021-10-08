class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> parents (n, -1);
        for (auto &edge: edges) {
            int parent = edge[0];
            while (parents[parent] !=-1) {
                parent = parents[parent];
            }
            parents[edge[1]] = parent;
        }
        vector<int> ans;
        for (int i=0; i<n; i++) {
            if (parents[i]==-1) ans.push_back (i);
        }
        return ans;
    }
};