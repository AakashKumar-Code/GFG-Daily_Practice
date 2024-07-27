//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
    
    int find(int i, vector<int>&parent){
        if(i==parent[i]){
            return i;
        }
        return parent[i]=find(parent[i], parent);
    }
    
    void unionF(int x, int y, vector<int>&parent, vector<int>&rank){
        int x_parent=find(x, parent);
        int y_parent=find(y, parent);
        
        if(x_parent==y_parent){
            return;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int>parent(V);
	    vector<int>rank(V);
	    for(int i=0; i<V; i++){
	        parent[i]=i;
	        rank[i]=1;
	    }
	    
	    for(int u=0; u<V; u++){
	        for(auto &v:adj[u]){
	            if(u<v){
	                int u_par=find(u, parent);
    	            int v_par=find(v, parent);
    	            if(u_par==v_par) return true;
    	            unionF(u, v, parent, rank);
	            }
	        }
	    }
	    return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends