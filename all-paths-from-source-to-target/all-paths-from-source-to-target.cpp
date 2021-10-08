class Solution {
public:
    void dfs (vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int> &curr, int node) {
        curr.push_back (node);
        if (node == graph.size()-1) {
            ans.push_back (curr);
        }
        for (int i=0; i<graph[node].size(); i++) {
            dfs (graph, ans, curr, graph[node][i]);
        }
        curr.pop_back ();
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs (graph, ans, curr, 0);
        return ans;
    }
};