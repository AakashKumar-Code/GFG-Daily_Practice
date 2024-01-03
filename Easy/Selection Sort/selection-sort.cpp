//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}


// } Driver Code Ends
class Solution
{
    public:
    int N;
    int select(int arr[], int i)
    {
        // code here such that selectionSort() sorts arr[]
        int mini=1e9;
        int ind=-1;
        for(int j=i; j<N; j++){
            if(arr[j]<mini){
                ind=j;
                mini=arr[j];
            }
        }
        return ind;
    }
     
    void selectionSort(int arr[], int n)
    {
       //code here
       N=n;
       for(int i=0; i<n; i++){
           int ind=select(arr, i);
           swap(arr[i], arr[ind]);
       }
       return;
    }
};

//{ Driver Code Starts.
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[1000],n,T,i;
  
    scanf("%d",&T);
    
    while(T--){
        
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      
    Solution ob;  
    ob.selectionSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}

// } Driver Code Ends