class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> color (n, -1);
        for (int i=0; i<n; i++) {
            if (color[i]!=-1) continue;
            queue <int> q;
            q.push (i);
            color[i] = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto nbr: graph[node]) {
                    if (color[nbr]==-1) {
                        q.push(nbr);
                        color[nbr] = color[node]^1;
                    }
                    else if (color[nbr] == color[node]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};