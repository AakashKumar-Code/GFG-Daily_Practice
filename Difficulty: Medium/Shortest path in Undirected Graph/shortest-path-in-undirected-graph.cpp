//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    int n;
  
    void bfs(int src, unordered_map<int,vector<int>>&adj, vector<int>&ans){
        
        queue<pair<int, int>>q;
        q.push({src, 0});
        
        while(!q.empty()){
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                if(ans[it]>d+1){
                    ans[it]=1+d;
                    q.push({it, ans[it]});
                }
            }
        }
        
    }
  
    vector<int> shortestPath(vector<vector<int>>& edges, 
    int N,int M, int src){
        // code here
        n=N;
        
        unordered_map<int,vector<int>>adj;
        
        for(int i=0; i<M; i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>ans(N, 1e9);
        
        ans[src]=0;
        
        bfs(src, adj, ans);
        
        for (int i = 0; i < N; i++) {
            if (ans[i] == 1e9) {
                ans[i] = -1;
            }
        }
        
        return ans;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends