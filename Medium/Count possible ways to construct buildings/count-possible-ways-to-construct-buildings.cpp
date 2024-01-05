//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	const int mod=1e9+7;
	int TotalWays(int N)
	{
	    // Code here
	    unsigned long long ob=1;
	    unsigned long long os=1;
	    for(int i=2; i<=N; i++){
	        unsigned long long nb=os;
	        unsigned long long ns=(ob+os);
	        
	        os=ns%mod;
	        ob=nb%mod;
	    }
	    unsigned long long tot=(ob+os)%mod;
	    return (tot*tot)%mod;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends