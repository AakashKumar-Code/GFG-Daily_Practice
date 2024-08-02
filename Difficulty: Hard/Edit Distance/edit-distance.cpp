//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int editDistance(string s, string t) {
        // Code here
        
        int x=s.size();
        int y=t.size();
        vector<vector<int>>dp(x+1, vector<int>(y+1, 0));
        
        for(int i=0; i<=x; i++){
            dp[i][0]=i;
        }
        for(int j=0; j<=y; j++){
            dp[0][j]=j;
        }
        
        for(int i=1; i<=x; i++){
            for(int j=1; j<=y; j++){
               if(s[i-1]==t[j-1]){
                     dp[i][j]=dp[i-1][j-1];
               }else{
                     int ins=1+dp[i-1][j];
                     int del=1+dp[i][j-1];
                     int sub=1+dp[i-1][j-1];
                     dp[i][j]=min(ins, min(del, sub));
                    } 
            }
        }
        
        return dp[x][y];
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends