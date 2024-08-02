//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> tree;
    
    vector<int> merge(vector<int> &left, vector<int> &right){
        vector<int> freq(26,0);
        for(int i=0;i<26;i++){
            freq[i]=left[i]+right[i];
        }
        return freq;
    }
    
    void buildTree(string &s, int start, int end, int parent){
        if(start==end){
            tree[parent][s[start]-'a']++;
            return;
        }
        int mid=(start+end)/2;
        buildTree(s,start,mid,2*parent+1);
        buildTree(s,mid+1,end,2*parent+2);
        tree[parent]=merge(tree[2*parent+1],tree[2*parent+2]);
        return;
    }
    
    void update(int start, int end, int parent, int index, char c){
        if(start>end){
            return;
        }
        if(start==end){
            vector<int> freq(26,0);
            freq[c-'a']++;
            tree[parent]=freq;
            return;
        }
        int mid=(start+end)/2;
        if(index>mid){
            update(mid+1,end,2*parent+2,index,c);
        }
        else{
            update(start,mid,2*parent+1,index,c);
        }
        tree[parent]=merge(tree[2*parent+1],tree[2*parent+2]);
        return;
    }
    
    vector<int> querySolver(int start, int end, int qstart, int qend, int parent){
        if(qstart>end || qend<start){
            return vector<int>(26,0);
        }
        if(qstart<=start && qend>=end){
            return tree[parent];
        }
        int mid=(start+end)/2;
        auto L=querySolver(start,mid,qstart,qend,2*parent+1);
        auto R=querySolver(mid+1,end,qstart,qend,2*parent+2);
        return merge(L,R);
    }
    
    vector<char> easyTask(int n,string s,int q,vector<vector<string>> &queries){
        tree.resize(4*n+1,vector<int>(26,0));
        buildTree(s,0,n-1,0);
        vector<char> res;
        for(auto query: queries){
            int type=stoi(query[0]);
            if(type==1){
                int index=stoi(query[1]);
                char c=query[2][0];
                update(0,n-1,0,index,c);
            }
            else{
                int left=stoi(query[1]);
                int right=stoi(query[2]);
                int k=stoi(query[3]);
                auto freq=querySolver(0,n-1,left,right,0);
                for(int i=25;i>=0;i--){
                    k-=freq[i];
                    if(k<=0){
                        res.push_back(i+'a');
                        break;
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int q;
        cin>>q;
        vector<vector<string>> queries(q);
        for(int i=0;i<q;i++){
            string x;
            cin>>x;
            if(x=="1"){
                string p,q;
                cin>>p>>q;
                queries[i]={"1",p,q};
            }
            else{
                string p,q,r;
                cin>>p>>q>>r;
                queries[i]={"2",p,q,r};
            }
        }
        Solution ob;
        vector<char> ans=ob.easyTask(n,s,q,queries);
        for(auto ch:ans){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends