//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        int first=0;
        int second=1;
        int sum=0;
        
        if(n==1)
        {
            return 1;
        }
        
        for(int i=1 ; i<n;i++)
        {
            sum= (first+second)%1000000007;
            first=second;
            second=sum;
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends