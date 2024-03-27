//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
        vector<vector<int>> temp=mat;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0){
                    int dr[]={-1,0,1,0};
                    int dc[]={0,-1,0,1};
                    for(int k=0; k<4; k++){
                        int nr=i+dr[k];
                        int nc=j+dc[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<m){
                            temp[nr][nc]=0;
                        }
                    }
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        for(int i=0; i<n; i++){
            if(temp[i][0]!=0){
                pq.push({1,{i,0}});
                dist[i][0]=1;
            }
        }
        while(!pq.empty()){
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(c==m-1){
                return d;
            }
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    if(temp[nr][nc]!=0){
                        if(dist[nr][nc]>d+1){
                            dist[nr][nc]=d+1;
                            pq.push({d+1,{nr,nc}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends