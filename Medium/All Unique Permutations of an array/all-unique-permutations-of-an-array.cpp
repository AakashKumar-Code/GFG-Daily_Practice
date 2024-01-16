//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    vector<vector<int>> ans;

    void solve(int ind, int n, vector<int>& arr) {
        if (ind >= n) {
            ans.push_back(arr);
            return;
        }
        unordered_set<int> st;
        for (int i = ind; i < n; i++) {
            if (st.find(arr[i]) != st.end()) continue;
            st.insert(arr[i]);
            swap(arr[i], arr[ind]);
            solve(ind + 1, n, arr);
            swap(arr[ind], arr[i]);
        }
    }
    
    vector<vector<int>> uniquePerms(vector<int>& arr, int n) {
        ans.clear();
        solve(0, n, arr);
        sort(ans.begin(), ans.end());  // Now, sort the result
        ans.erase(unique(ans.begin(), ans.end()), ans.end());  // Remove duplicates
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends