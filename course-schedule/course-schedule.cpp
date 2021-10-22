class Graph {
private:
    int V;
    vector <vector <int>> adj;
    vector <int> indegree;
public:
    Graph (int V) {
        this->V = V;
        adj.resize (V);
        indegree.resize(V, 0);
    }
    
    void addEdge (int n1, int n2) {
        adj[n2].push_back (n1);
        indegree[n1]++;
    }
    

    void print () {
        cout << V << endl;
        for (int i=0; i<V; i++) {
            cout << i << "->";
            for (int nbr: adj[i]) cout << nbr <<",";
            cout <<endl;
        }
    }
    
    bool solve () {
        queue<int>q;
        int seen =0;
        for (int i=0; i<V; i++) if (indegree[i]==0) q.push(i);
        while (!q.empty()) {
            seen++;
            int node = q.front();
            q.pop();
            for (int &nbr: adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr]==0) q.push(nbr);
            }
        }
        return seen==V;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        Graph g  = Graph (numCourses);
        for (auto &edge: prerequisites) {
            g.addEdge (edge[0], edge[1]);
        }
        
        return g.solve();
    }
};