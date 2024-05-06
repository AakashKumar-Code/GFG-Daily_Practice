//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
vector<int> noSibling(Node *root);

int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        vector<int> res = noSibling(root);
        for (int i = 0; i < res.size(); ++i)
        {
            cout<<res[i]<<" ";
        }
        cout<<endl;
  }
  return 0;
}

// } Driver Code Ends


//User function Template for C++

/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

void inorder(Node *root , unordered_map<int,vector<int>>&mp)
{
    if(root==NULL)
        return;
    
   
   if(root->left!=NULL)
   {
    mp[root->data].push_back(root->left->data);
    inorder(root->left ,mp);
    
   }
   
   if(root->right!=NULL)
   {
    mp[root->data].push_back(root->right->data);
    inorder(root->right ,mp);
    
   } 
}

 

vector<int> noSibling(Node* node)
{
   
   
   
    unordered_map<int,vector<int>>mp;
    
    
    vector<int>res; 
    
    inorder(node,mp);
   
    
    for(auto it =  mp.begin(); it != mp.end(); it++) {
    // Your code here
 
       vector<int>temp = it->second;
       
       if(temp.size()==1)
       {
           res.push_back(temp[0]);
       }
       
   }
   
    if(res.size()==0)
        return {-1};
        
    
    sort(res.begin(),res.end());
    
    return res;
   
   
   
   
}

