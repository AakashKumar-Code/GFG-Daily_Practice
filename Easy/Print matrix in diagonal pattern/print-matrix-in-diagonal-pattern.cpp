//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int n=mat.size();
         vector<int>ans;
         for(int k=0; k<=2*n-2; k++){
             vector<int>temp;
             for(int row=0; row<n; row++){
                 for(int col=0; col<n; col++){
                     if(row+col==k){
                         temp.push_back(mat[row][col]);
                     }
                 }
             }
             if(k%2==0) reverse(temp.begin(), temp.end());
             ans.insert(ans.end(), temp.begin(), temp.end());
         }
         return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends