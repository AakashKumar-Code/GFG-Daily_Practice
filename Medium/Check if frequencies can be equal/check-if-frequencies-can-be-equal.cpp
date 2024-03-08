//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s1)
{
  vector<int>v(26,0);
  for(auto &x:s1)v[x-'a']++;
map<int,int>mp;
   vector<int>v1;
  for(int i=0;i<26;i++){
      if(v[i]!=0){
          v1.push_back(v[i]);
          mp[v[i]]++;
      }
  }
  if(mp.size()==1) return true;
  else{
    for(int i=0;i<v1.size();i++){
     set<int>s;
        for(int j=0;j<v1.size();j++){
            if(i==j){
                if(v1[j]-1>0)
                s.insert(v1[j]-1);
            }
            else s.insert(v1[j]);
        }
        if(s.size()==1) return true;
    }
    
    return false;
  }
   
}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends