//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class DisjointSet {
    vector<int> rank, parent;
public:
    vector<int>child;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        child.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
 
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
 
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
            child[ulp_v]+=child[ulp_u];
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
            child[ulp_u]+=child[ulp_v];
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
            child[ulp_u]+=child[ulp_v];
        }
    }
};
class Solution{
	public:
	static bool comp(vector<int>a,vector<int>b){
    return a[2]<b[2];
}
vector<int> maximumWeight(int n, vector<vector<int>> edges, int k, vector<int> &queries)
{
    // code here
    vector<int>ans(queries.size(),0);
    vector<vector<int>>q;
    for(int i=0;i<queries.size();i++) q.push_back({queries[i],i});
    sort(q.begin(),q.end());
    sort(edges.begin(),edges.end(),comp);
    int val=0;
    DisjointSet ds(n+1);
    int j=0;
    unordered_map<int,int>mp;
    for(int i=0;i<q.size();i++){
        while(j<edges.size()&&edges[j][2]<=q[i][0]){
            int par1=ds.findUPar(edges[j][0]);
            int par2=ds.findUPar(edges[j][1]);
            if(mp.find(par1)!=mp.end())val-=((mp[par1])*(mp[par1]-1))/2;
            if(mp.find(par2)!=mp.end()) val-=((mp[par2])*(mp[par2]-1))/2;
            ds.unionByRank(edges[j][0],edges[j][1]);
            int par=ds.findUPar(edges[j][0]);
            mp[par]=ds.child[par];
            //cout<<val<<endl;
            val+=((mp[par])*(mp[par]-1))/2;
            j++;
        }
        
        ans[q[i][1]]=val;
    }
    return ans;
}
};



//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    }
    return 0;
}

// } Driver Code Ends