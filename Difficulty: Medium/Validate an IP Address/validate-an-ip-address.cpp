//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        int n=str.size();
        
        for(int i=1; i<n; i++){
            if(str[i-1]=='.' && str[i]=='.') return 0;
            if((str[i]>='0' && str[i]<='9') || str[i]=='.'){
                continue;
            }else return 0;
        }
        if(str[0]=='.' || str[n-1]=='.') return 0;
        
        
        stringstream ss(str);
        string token;
        int cnt=0;
        
        while (getline(ss, token, '.')) {
            cnt++;
            if(token[0]=='0' && token.size()>1) return 0;
            int num=stoi(token);
            if(num<0 || num>255) return 0;
        }
        return cnt==4?1:0;
        
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends