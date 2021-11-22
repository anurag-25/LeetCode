#define pii pair<int,int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector< pair<int, int> >> adj (n+1);
        for (auto &edge: times) {
            adj[edge[0]].push_back ( {edge[1], edge[2]} );
        }
        vector<int> dist (n+1, 10001);
        priority_queue < pii , vector<pii>, greater<pii> > pq;
        dist[k] = 0;
        pq.push ({0,k});
        
        while (!pq.empty()) {
            int node = pq.top().second, len = pq.top().first;
            pq.pop();
            
            for (auto &nbr: adj[node]) {
                int dest = nbr.first , weight = nbr.second ;
                if (dist[dest] > dist[node]+weight) {
                    dist[dest] = dist[node]+weight;
                    pq.push ( {dist[dest], dest} );
                }
            }
        }
        int ans = 0;
        for (int i=1; i<=n; i++){
            if (dist[i] == 10001) return -1;
            ans = max (ans, dist[i]);
        }
        return ans;
    }
};