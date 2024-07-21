//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  
    const long long int mod=1e9+7;
    
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        int n=arr.size();
        if(n==1) return arr[0];
        
        
        int maxi=-1e9, idx=-1;
        int cnt=0;
        bool allZeroes=1;
        
        for(int i=0; i<n; i++){
            if(arr[i]<0){
                cnt++;
                if(arr[i]>maxi){
                    maxi=arr[i];
                    idx=i;
                }
            }
            if(arr[i]!=0) allZeroes=0;
        }
        
        if(allZeroes) return 0;
        
        long long int pro=1;
        
        if(n==2 && cnt==1){
            return max(arr[0], arr[1]);
        }
        
        if(cnt%2==0){
            for(int i=0; i<n; i++){
                if(arr[i]==0) continue;
                else{
                    pro=(pro*(abs(arr[i])))%mod;
                }
            }
        }else{
            for(int i=0; i<n; i++){
                if(arr[i]==0 || i==idx) continue;
                else{
                    pro=(pro*(abs(arr[i])))%mod;
                }
            }
        }
        return pro;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends