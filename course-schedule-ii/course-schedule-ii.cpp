class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto x: prerequisites) {
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }
        vector<int> ans;
        queue<int> q;
        for (int i=0; i<numCourses; i++) {
            if (indegree[i]==0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (auto &nbr: adj[node]) {
                indegree[nbr]--;
                if (indegree[nbr]==0) {
                    q.push(nbr);
                    ans.push_back(nbr);
                }
            }           
        }
        if (ans.size()<numCourses) return vector<int>{};
        return ans;
        
    }
};