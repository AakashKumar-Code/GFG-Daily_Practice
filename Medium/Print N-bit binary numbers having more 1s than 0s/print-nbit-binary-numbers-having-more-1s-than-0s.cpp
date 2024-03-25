//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void solve(int n, string k, int index, int zeroes, int ones, vector<string>& result) {
    if (index == n) {
        result.push_back(k);
        return;
    }
    solve(n, k + '1', index + 1, zeroes, ones + 1, result);
    if (zeroes < ones) {
        solve(n, k + '0', index + 1, zeroes + 1, ones, result);
    }
}

vector<string> NBitBinary(int n) {
    vector<string> result;
    string k = "1";
    solve(n, k, 1, 0, 1, result);
    sort(result.begin(), result.end(), greater<string>());
    return result;
}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends