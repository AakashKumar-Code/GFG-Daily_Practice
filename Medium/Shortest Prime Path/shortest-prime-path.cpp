//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    void sieve(vector<int>& primeNumbers)
    {
        for(int i=2;i<10001;i++)
        {
            if(primeNumbers[i]==0)
            {
                primeNumbers[i]=i;
                for(int j=i+i;j<10001;j+=i)
                {
                    if(primeNumbers[j]==0)
                    {
                        primeNumbers[j]=i;
                    }
                }
            }
        }
    }
    int solve(int n1,int n2)
    {   
        if(n1==n2)return 0;
        vector<int> primeNumbers(10001,0);
        sieve(primeNumbers);
        string s1=to_string(n1);
        string s2=to_string(n2);
        set<int> st;
        queue<pair<string,int>> q;
        q.push({s1,0});
        st.insert(n1);
        while(!q.empty())
        {
            auto p=q.front();
            q.pop();
            if(p.first==s2)return p.second;
          
            for(int j=0;j<p.first.size();j++)
            {
                char ch=p.first[j];
                int ind=ch-'0';
                for(int i=0;i<10;i++)
                {
                    if(j==0 && i==0)continue;
                    if(ind!=i)
                    {
                        string s=p.first;
                        s[j]=char(i+48);
                        
                        int x=stoi(s);
          
                        if(primeNumbers[x]==x && st.find(x)==st.end())
                        {
                            st.insert(x);
                            q.push({s,p.second+1});
                            
                        }
                    }
                }
            }
           
            
        }
         return -1;
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int Num1,Num2;
      cin>>Num1>>Num2;
      Solution obj;
      int answer=obj.solve(Num1,Num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends