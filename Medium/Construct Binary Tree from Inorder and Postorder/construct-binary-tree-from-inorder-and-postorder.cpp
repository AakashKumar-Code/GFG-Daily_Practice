//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution
{
    public:

    //Function to return a tree created from postorder and inoreder traversals.
    
     Node *buildTree(int in[], int post[], int n) {
        // Your code here
        unordered_map<int, int> val2in;
        for (int i = 0; i < n; i++) val2in[in[i]] = i;
        
        return build(in, post, n, val2in, n, 0, 0);
    }
    
    Node *build(int in[], int post[], int n, unordered_map<int, int>& val2in, int sz, int instart, int poststart) {
        if (sz == 0) return NULL;
        
        Node *node = new Node(post[poststart+sz-1]);
        if (sz == 1) return node;
        
        int rootpos_inorder = val2in[post[poststart+sz-1]];
        int lsz = rootpos_inorder-instart;
        int rsz = sz-lsz-1;
        
        node->left = build(in, post, n, val2in, lsz, instart, poststart);
        node->right = build(in, post, n, val2in, rsz, instart+lsz+1, poststart+lsz);
        return node;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends