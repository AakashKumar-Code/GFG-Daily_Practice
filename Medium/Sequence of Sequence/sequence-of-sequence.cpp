//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int m, int n, int len, int num){
        if(len==n){
           return 1;
        }
        if(num>m) return 0;
        
        // pick or not Pick
        int notPick = f(m,n,len,num+1);
        int pick = f(m,n,len+1,num*2); 
        return notPick + pick;
    }
    int numberSequence(int m, int n){
        // code here
        return f(m,n,0,1);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends