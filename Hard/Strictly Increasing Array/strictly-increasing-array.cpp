//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int solve(vector<int> &nums,int curr,int prev,int n,vector<vector<int>> &dp)
    {
        if(curr>=n)
          return 0;
        if(dp[curr][prev+1]!=-1)
          return dp[curr][prev+1];
          int incl=0;
         int excl=0+solve(nums,curr+1,prev,n,dp);
        if(prev==-1 || nums[curr]>nums[prev] && nums[curr]-nums[prev]>=curr-prev){
            incl=1+solve(nums,curr+1,curr,n,dp);
        }
        return dp[curr][prev+1]=max(incl,excl);
    }
    int min_operations(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int lenOfIncSubSeq=solve(nums,0,-1,n,dp);
        return n-lenOfIncSubSeq;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends