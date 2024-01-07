//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int stud(int arr[] ,int N,int p){
      int s=1;
      int pg=0;
      for(int i=0;i<N;i++){
          if(pg+arr[i]<=p)pg=pg+arr[i];
          else{
              s++;
              pg=arr[i];
          }
      }
      return s;
  }
    int splitArray(int arr[] ,int N, int K) {
        int l=0;
        int h=0;
        for(int i=0;i<N;i++){
            h+=arr[i];
            l=max(l,arr[i]);
        }
        while(l<=h){
            int m =l+ (h-l)/2;
            int num = stud(arr,N,m);
            if(num>K)l=m+1;
            else h=m-1;
            
        }
        return l;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends