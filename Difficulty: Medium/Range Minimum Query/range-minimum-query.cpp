//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends


    /* The functions which 
    builds the segment tree */
    
    void bT(int i, int l, int r, int st[], int arr[]){
        if(l==r){
            st[i]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        bT(2*i+1, l, mid, st, arr);
        bT(2*i+2, mid+1, r, st, arr);
        st[i]=min(st[2*i+1], st[2*i+2]);
    }
    
    int *constructST(int arr[],int n)
    {
        int* st = new int[4 * n];
        
        fill(st, st + 4 * n, 1e9);
        
        bT(0, 0, n-1, st, arr);
        return st;
    }
    
    
    /* The functions returns the
     min element in the range
     from a and b */
     
    int getMin(int i, int l, int r, int s, int e, int st[]){
        if(l>e || r<s){
            return 1e9;
        }
        if(l>=s && r<=e){
            return st[i];
        }
        int mid=l+(r-l)/2;
        return min(getMin(2*i+1, l, mid, s, e, st), 
                   getMin(2*i+2, mid+1, r, s, e, st));
    }
     
    int RMQ(int st[] , int n, int a, int b)
    {
        //Your code here
        return getMin(0, 0, n-1, a, b, st);
         
    }