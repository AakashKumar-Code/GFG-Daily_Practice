//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:



unordered_set<string> st;
int len;
int dp[1101];

bool solve(int ind, string &s) {
    if (ind == len) return true;
    if (dp[ind] != -1) return dp[ind];

    string temp = "";
    for (int i = ind; i < len; i++) {
        temp += s[i];
        if (st.find(temp) != st.end() && solve(i + 1, s)) {
            return dp[ind] = 1;
        }
    }
    return dp[ind] = 0;
}

int wordBreak(int n, string s, vector<string>& dictionary) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        st.insert(dictionary[i]);
    }
    len = s.length();
    return solve(0, s);
}

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends