//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    Node* node1, *node2;
int A, B;
unordered_map<Node*, Node*> parent;

void markP(Node* root, Node* par) {
    if (root == NULL) return;
    parent[root] = par;
    if (root->data == A) node1 = root;
    else if (root->data == B) node2 = root;
    markP(root->left, root);
    markP(root->right, root);
}

int findDist(Node* root, int a, int b) {
    // Your code here
    if(a==b) return 0;
    A = a, B = b;
    node1 = NULL, node2 = NULL;
    markP(root, NULL);
    unordered_set<Node*> vis;
    int cnt = -1;
    queue<Node*> q;
    q.push(node1);
    vis.insert(node1);
    while (!q.empty()) {
        cnt++;
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Node* node = q.front();
            q.pop();
            if (node == node2) return cnt;
            if (node->left && vis.find(node->left) == vis.end()) {
                vis.insert(node->left);
                q.push(node->left);
            }
            if (node->right && vis.find(node->right) == vis.end()) {
                vis.insert(node->right);
                q.push(node->right);
            }
            if (parent[node] && vis.find(parent[node]) == vis.end()) {
                vis.insert(parent[node]);
                q.push(parent[node]);
            }
        }
    }
    return -1;
}

};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends