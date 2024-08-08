//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int Maximize(vector<int> arr) {
        // Complete the function
        int n=arr.size();
        if(n==1) return 0;
        sort(arr.begin(), arr.end());
        long long mod=1e9+7;
        long long ans=0;
        
        for(int i=0; i<n; i++){
            long long tmp=(long long)((long long)i*(long long)arr[i])%mod;
            ans=(ans+tmp)%mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends