//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        vector<int>freq(26, 0);
        int n=s.length();
        
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }
        
        priority_queue<int>pq;
        
        for(int i=0; i<26; i++){
            pq.push(freq[i]);
        }
        
        while(k){
            int top=pq.top();
            pq.pop();
            pq.push(top-1);
            k--;
        }
        
        int ans=0;
        while(!pq.empty()){
            int top=pq.top();
            pq.pop();
            ans+=(top*top);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends