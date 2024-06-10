//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {

        string order = "!#$%&*?@^";

        unordered_map<char, int> orderMap;

        

 

        for (int i = 0; i < order.size(); ++i) {

            orderMap[order[i]] = i;

        }

        

        auto comparator = [&orderMap](char a, char b) {

            return orderMap[a] < orderMap[b];

        };

        sort(nuts, nuts + n, comparator);

        sort(bolts, bolts + n, comparator);

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(n, nuts, bolts);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends