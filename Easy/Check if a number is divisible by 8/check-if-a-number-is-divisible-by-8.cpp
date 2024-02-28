//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int n=s.length();
        int i=n-1;
        int num=0;
        if(n<3){
            num=stoi(s);
            if(num%8==0 || num==0) return 1;
        }else{
            for(int i=n-3; i<n; i++){
                num=(num*10)+s[i];
            }
            if(num%8==0 || num==0) return 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends