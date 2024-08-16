//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {

        // code here
        int n=nums.size();
        unsigned long long int st=1, end=1;
        vector<long long int>fromSt(n), fromE(n), ans(n, 1);
        
        for(int i=0; i<n; i++){
            st*=nums[i];
            fromSt[i]=st;
            end*=nums[n-i-1];
            fromE[n-i-1]=end;
        }
        
        for(int i=0; i<n ; i++){
            if(i>0) ans[i]*=fromSt[i-1];
            if(i<n-1) ans[i]*=fromE[i+1];
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends