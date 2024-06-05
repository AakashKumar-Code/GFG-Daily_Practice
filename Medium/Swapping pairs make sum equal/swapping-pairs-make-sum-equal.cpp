//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
     int findSwapValues(int a[], int n, int b[], int m) {
        int sumA=0;
        int sumB=0;
        for(int i=0;i<n;i++) sumA += a[i];
        for(int j=0;j<m;j++) sumB += b[j];
        
        if((sumB-sumA)%2!=0) return -1;
        int diff = (sumB-sumA)/2;
        unordered_set<int> setB;
        for(int i=0;i<m;i++) setB.insert(b[i]);
        for(int i=0;i<n;i++){
          if (setB.find(a[i] + diff) != setB.end()) return 1;
        }
        return -1;
      }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends