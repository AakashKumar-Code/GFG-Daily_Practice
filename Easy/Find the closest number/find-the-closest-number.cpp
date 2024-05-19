//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int ans=1e9;
        int lo=0;
        int hi=n-1;
        
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==k) return k;
            else{
                if(abs(ans-k)>abs(arr[mid]-k)){
                    ans=arr[mid];
                }else if(abs(ans-k)==abs(arr[mid]-k)){
                    ans=max(ans, arr[mid]);
                }
                if(arr[mid]<k){
                    lo=mid+1;
                }else{
                    hi=mid-1;
                }
            }
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends