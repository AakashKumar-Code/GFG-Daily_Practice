//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
     int mincost(int &n, int w, vector<int>& cost, vector<int>& dp){
        if(w <= 0){
            if(w == 0){
                return 0;
            }
            return INT_MAX;
        }
        else if(dp[w] != -1){
            return dp[w];
        }
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++){
            if(w - i >= 0 && cost[i-1] > 0){
                int val = mincost(n, w - i, cost, dp);
                if(val != INT_MAX){
                    ans = min(ans, val + cost[i-1]);
                }
            }
        }
        return dp[w] = ans;
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<int>dp(w+1,-1);
        mincost(n, w, cost, dp);
        return dp[w] == INT_MAX ? -1 : dp[w];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends