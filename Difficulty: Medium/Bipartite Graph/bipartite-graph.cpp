//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int curr, int currColor, vector<int>adj[], vector<int>&color){
        color[curr]=currColor;
        for(int &ngbr:adj[curr]){
            if(color[ngbr]==currColor){
                return 0;
            }else if(color[ngbr]==-1){
                int ngbrColor=1-currColor;
                if(dfs(ngbr, ngbrColor, adj, color)==0){
                    return 0;
                }
            }
        }
        return 1;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>color(V, -1);
	    
	    for(int i=0; i<V; i++){
	        if(color[i]==-1){
	            if(dfs(i, 0, adj, color)==0){
	                return 0;
	            }
	        }
	    }
	    return 1;
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
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends