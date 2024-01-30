//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
        int solve(int i, int j, int k, string &s1, string &s2, string &s3,
          vector<vector<vector<int>>> &dp) {
    if (i < 0 || j < 0 || k < 0) return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    if (s1[i] == s2[j] && s2[j] == s3[k]) {
        return dp[i][j][k] = (1 + solve(i - 1, j - 1, k - 1, s1, s2, s3, dp));
    } else {
        int l = solve(i - 1, j, k, s1, s2, s3, dp);
        int r = solve(i, j - 1, k, s1, s2, s3, dp);
        int p = solve(i, j, k - 1, s1, s2, s3, dp);
        return dp[i][j][k] = (max(l, max(r, p)));
    }
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3) {
    // your code here
    int n = max({n1, n2, n3});
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
    return solve(n1 - 1, n2 - 1, n3 - 1, A, B, C, dp);
}

};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends