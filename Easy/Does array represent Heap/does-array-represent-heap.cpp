//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        queue<int>q;
        int i=0;
        q.push(arr[i]);
        i++;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(i==n) break;
            if(i<n){
                if(arr[i]>node) return 0;
                q.push(arr[i]);
                i++;
            }
            if(i<n){
                if(arr[i]>node) return 0;
                q.push(arr[i]);
                i++;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends