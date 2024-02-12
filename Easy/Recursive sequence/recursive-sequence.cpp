//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    const int mod=1e9+7;

    long long sequence(int n){
        // code here
        unsigned long long ans=0;
        int k=1;
        long long i=1;
        while(k<=n){
            unsigned long long temp=1;
            for(int j=1; j<=k; j++){
                temp=(temp*i)%mod;
                i++;
            }
            ans=(ans+temp)%mod;
            k++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends