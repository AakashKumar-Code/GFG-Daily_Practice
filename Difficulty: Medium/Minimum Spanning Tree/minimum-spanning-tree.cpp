//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    
    int find(int x, vector<int>&par){
        if(x==par[x]){
            return x;
        }
        return par[x]=find(par[x], par);
    }
    
    void Union(int x, int y, vector<int>&par, vector<int>&rank){
        int par_x=find(x, par);
        int par_y=find(y, par);
        
        if(par_x==par_y) return;
        
        if(rank[par_x]>rank[par_y]){
            par[par_y]=par_x;
        }else if(rank[par_x]<rank[par_y]){
            par[par_x]=par_y;
        }else{
            par[par_x]=par_y;
            rank[par_y]++;
        }
    }
    
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<vector<int>>vec;
        for(int i=0; i<V; i++){
            for(auto &it:adj[i]){
                vec.push_back({it[1], i, it[0]});
            }
        }
        
        sort(vec.begin(), vec.end());
        int ans=0;
        vector<int>par(V), rank(V, 0);
        
        for(int i=0; i<V; i++) par[i]=i;
        
        for(auto &it:vec){
            int u=it[1];
            int v=it[2];
            int wt=it[0];
            
            int par_u=find(u, par);
            int par_v=find(v, par);
            
            if(par_u!=par_v){
                ans+=wt;
                Union(u, v, par, rank);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends