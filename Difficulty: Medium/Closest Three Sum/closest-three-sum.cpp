//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        
        int n=arr.size();
        
        int mini=1e9;
        int ans=1e9;
        
        for(int k=0; k<n-2; k++){
            int i=k+1, j=n-1;
            while(i<j){
                int sum=arr[i]+arr[j]+arr[k];
                
                int diff=abs(target-sum);
                if(mini>diff){
                    mini=diff;
                    ans=sum;
                }else if(mini==diff){
                    ans=max(ans, sum);
                }
                
                if(sum>target) j--;
                else if(sum==target) return target;
                else i++;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends