//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define mod 1003
class Solution{
public:
#define long long ll

    int f(int i, int j, int isTrue, string &S, vector<vector<vector<int>>>&dp){
        if(i>j) return 0;
        if(i==j){
            if(isTrue){
                return S[i]=='T';
            }else{
                return S[i]=='F';
            }
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue]%mod;
        
        int ways=0;
        for(int ind=i+1; ind<=j-1; ind+=2){
            int lT=f(i, ind-1, 1, S, dp);
            int lF=f(i, ind-1, 0, S, dp);
            int rT=f(ind+1, j, 1, S, dp);
            int rF=f(ind+1, j, 0, S, dp);
        
        if(S[ind]=='&'){
            if(isTrue){
                ways+=lT*rT;
            }else{
                ways+=lF*rT+rF*lT+lF*rF;
            }
        }else if(S[ind]=='|'){
            if(isTrue){
                ways+=lF*rT+rF*lT+lT*rT;
            }else{
                ways+=lF*rF;
            }
        }else{
            if(isTrue){
                ways+=lT*rF+rT*lF;
            }else{
                ways+=lT*rT+lF*rF;
            }
          }
        }
        
        return dp[i][j][isTrue]=ways%mod;
    }

    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>>dp(N+1, vector<vector<int>>(N+1, vector<int>(2, -1)));
        return f(0, N-1, 1, S, dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends