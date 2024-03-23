//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        if(n<=0) return {n};
        if(n==1) return {0, 1};
        int prev2=0;
        int prev=1;
        vector<int>ans;
        int mod=1e9+7;
        ans.push_back(prev2);
        ans.push_back(prev);
        for(int i=2; i<=n; i++){
            int cur=(prev2+prev)%mod;
            ans.push_back(cur);
            prev2=prev;
            prev=cur;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends