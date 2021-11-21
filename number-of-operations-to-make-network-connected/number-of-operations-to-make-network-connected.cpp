class Solution {
    vector <int> parent, rank;
    
    int find (int node) {
        if (parent[node]==-1) return node;
        return parent[node] = find (parent[node]);
    }
    
    void union_ (int n1, int n2) {
        int p1 = find (n1), p2 = find (n2);
        if (p1 == p2) return;
        if (rank[p1] >= p2) {
            parent[p2] = p1;
            rank[p1]++;
        }
        else {
            parent[p1] = p2;
            rank[p2]++;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        parent.resize (n, -1), rank.resize(n, 0);
        for (auto connection: connections) {
            union_ (connection[0], connection[1]);
        }
        
        int ans = 0;
        for (int &p: parent) 
            if (p==-1) ans++;
        return --ans;
    }
};