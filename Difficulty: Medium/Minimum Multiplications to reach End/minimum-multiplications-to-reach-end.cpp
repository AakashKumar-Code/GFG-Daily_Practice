// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start==end) return 0;
        queue<int>q;
        q.push(start);
        int mod=1e5;
        int n=arr.size();
        
        vector<int>dist(100001, -1);
        dist[start]=0;
        
        
        while(!q.empty()){
            int node=q.front();
                q.pop();
                
                for(int i=0; i<n; i++){
                    int newNode = (1LL * node * arr[i]) % mod;
                    if(newNode==end) return dist[node]+1;
                    else if(dist[newNode]==-1){
                        dist[newNode]=dist[node]+1;
                        q.push(newNode);
                    }
                }
        }
        
        return -1;
    }
};
