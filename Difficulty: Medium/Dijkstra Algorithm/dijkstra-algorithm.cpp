class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<int>>adj[V];
        
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        vector<int>dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>>pq;
        
        dist[src]=0;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto it=pq.top();
            int node=it.second;
            int d=it.first;
            pq.pop();
            
            if (d > dist[node]) continue;
            
            for(auto &it:adj[node]){
                int adjN=it[0];
                int adjW=it[1];
                if(dist[adjN]>d+adjW){
                    dist[adjN]=d+adjW;
                    pq.push({dist[adjN], adjN});
                }
            }
        }
        
        return dist;
    }
};