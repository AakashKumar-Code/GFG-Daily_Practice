//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        
        vector<int>cols;
        
        for(int row=0; row<n; row++){
            int sum=0;
            for(int col=0; col<n; col++){
                sum+=mat[row][col];
            }
            if(sum==0) cols.push_back(row);
        }
        
        int sz=cols.size();
        if(sz==0) return -1;
        
        for(int i=0; i<sz; i++){
            int col=cols[i];
            bool isCeleb=1;
            for(int row=0; row<n; row++){
                if(row==col) continue;
                else{
                    if(mat[row][col]==0){
                        //return row;
                        isCeleb=0;
                        break;
                    }
                }
            }
            if(isCeleb) return col;
        }
        return -1;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends