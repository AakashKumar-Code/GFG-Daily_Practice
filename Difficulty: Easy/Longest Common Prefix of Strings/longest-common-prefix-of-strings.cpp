//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string mini=arr[0];
        int n=arr.size();
        
        for(int i=1; i<n; i++){
            mini=min(mini, arr[i]);
        }
        
        
        for(int i=0; i<n; i++){
            string temp="";
            int sz=mini.size();
            for(int j=0; j<sz; j++){
                if(mini[j]==arr[i][j]){
                    temp+=mini[j];
                }else break;
            }
            mini=temp;
        }
        return mini.empty()?"-1":mini;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends