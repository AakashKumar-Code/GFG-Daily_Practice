//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int>ans;
  void solve(int x2,int y2,int x1,int y1,vector<vector<int>>&mat){
                int n=mat.size();
                int m=mat[0].size();
                 if(x2<0||x2>=n||y2<0||y2>=m) {
                     ans.push_back(x1);
                     ans.push_back(y1);
                     return;
                 }
                 if(mat[x2][y2]==0){
                        if(x1==x2&&(y1<y2)) {//left to right
                           solve(x2,y2+1,x2,y2,mat); 
                        } 
                        else if(x1==x2&&(y1>y2)) { //right to left 
                           solve(x2,y2-1,x2,y2,mat); 
                        }
                        else if(y1==y2&&(x1<x2)){ //top down 
                           solve(x2+1,y2,x2,y2,mat); 
                        }else if(y1==y2&&(x1>x2)){//down to top
                            solve(x2-1,y2,x2,y2,mat);
                        }
                        
                 }else if(mat[x2][y2]==1){ 
                        mat[x2][y2]=0;
                        if(x1==x2&&(y1<y2)) {//left to right 
                           solve(x2+1,y2,x2,y2,mat); 
                        } 
                        else if(x1==x2&&(y1>y2)) { //right to left 
                           solve(x2-1,y2,x2,y2,mat); 
                        }
                        else if(y1==y2&&(x1<x2)){ //top down 
                           solve(x2,y2-1,x2,y2,mat); 
                        }else if(y1==y2&&(x1>x2)){//down to top
                            solve(x2,y2+1,x2,y2,mat);
                        }
                 }
                 
    }
vector<int> FindExitPoint(int n, int  m,vector<vector<int>>& matrix) {
        
        solve(0,0,0,-1,matrix);
        return ans;
    } 
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends