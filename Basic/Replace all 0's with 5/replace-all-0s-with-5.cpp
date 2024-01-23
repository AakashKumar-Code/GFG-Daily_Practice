//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 
// Driver program to test above function

// } Driver Code Ends
class Solution{
  public:
    /*you are required to complete this method*/
    int convertFive(int n) {
    // Your code here
    int temp=n;
    int num=0;
    while(temp){
        if(temp%10==0){
            num=(num*10)+5;
        }else{
            num=(num*10)+(temp%10);
        }
        temp/=10;
    }
    temp=num;
    num=0;
    while(temp){
        num=(num*10)+(temp%10);
        temp/=10;
    }
    return num;
}
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n;
    	cin>>n;
    	Solution obj;
    	cout<<obj.convertFive(n)<<endl;
    }
}
// } Driver Code Ends