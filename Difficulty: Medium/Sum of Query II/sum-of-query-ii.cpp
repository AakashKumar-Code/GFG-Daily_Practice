//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++



class Solution{
public:

    void bT(int i, int l, int r, vector<int>&segTree, int arr[]){
        if(l==r){
            segTree[i]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        bT(2*i+1, l, mid, segTree, arr);
        bT(2*i+2, mid+1, r, segTree, arr);
        
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
            
    }
    
    int query(int i, int l, int r, int s, int e, vector<int>&segTree){
        
        if(l>e || r<s){
            return 0;
        }
        if(l>=s && r<=e){
            return segTree[i];
        }
        int mid=l+(r-l)/2;
        return query(2*i+1, l, mid, s, e, segTree)+query(2*i+2, mid+1, r, s, e, segTree);
        
    }
    
    

    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        // code here
        vector<int>segTree(4*n, 0);
        
        bT(0, 0, n-1, segTree, arr);
        
        vector<int>ans;
        
        for(int i=0; i<2*q; i+=2){
            int s=queries[i]-1;
            int e=queries[i+1]-1;
            ans.push_back(query(0, 0, n-1, s, e, segTree));
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n;
        int arr[n];
        for(int i = 0;i < n;i++)
            cin>>arr[i];
        cin>>q;
        int queries[2*q];
        for(int i = 0;i < 2*q;i += 2)
            cin>>queries[i]>>queries[i+1];
        
        Solution ob;
        vector<int> ans = ob.querySum(n, arr, q, queries);
        for(int u: ans)
            cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends