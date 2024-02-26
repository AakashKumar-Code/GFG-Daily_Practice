//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	    int n;
	
	    void solve(int i, string &s, string &temp, vector<string>&ans){
	        if(i==n){
	            if(temp.size()>0) ans.push_back(temp);
	            return;
	        }
	        temp+=s[i];
	        solve(i+1, s, temp, ans);
	        temp.pop_back();
	        solve(i+1, s, temp, ans);
	    }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    n=s.length();
		    vector<string>ans;
		    string temp="";
		    solve(0, s, temp, ans);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends