//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
        int i = 0, l1, l2, l3;
        int n = S.size();
        vector<int> arr(3, 0);
        int minAns = INT_MAX;
        bool found = false;
        while(i < n) {
            if(S[i] == '0') {
                l1 = i;
                arr[0] = 1;
            } else if(S[i] == '1') {
                l2 = i;
                arr[1] = 1;
            } else {
                l3 = i;
                arr[2] = 1;
            }
            if(arr[0] == 1 && arr[1] == 1 && arr[2] == 1) {
                found = true;
                int m1 = max(l1, max(l2, l3)), m2 = min(l1, min(l2, l3));
                int ans = abs(m1-m2) + 1;
                if(ans < minAns) {
                    minAns = ans;
                }
            }
            i++;
        }
        if(found) return minAns;
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends