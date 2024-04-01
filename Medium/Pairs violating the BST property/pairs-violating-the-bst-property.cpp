//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

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
        if (i >= ip.size())
            break;
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
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:

    /*You are required to complete below function */
     int merge(int low, int high, int mid, vector<int> &v)
    {
        int left = low;
        int right = mid+1;
        vector<int> temp;
        int cnt = 0;
        while(left <= mid && right <= high)
        {
            if(v[left] <= v[right])
            {
                temp.push_back(v[left]);
                left++;
            }
            else
            {
                temp.push_back(v[right]);
                right++;
                cnt += mid - left + 1;
            }
        }
        while(left <= mid)
        {
            temp.push_back(v[left]);
            left++;
        }
        while(right <= high)
        {
            temp.push_back(v[right]);
            right++;
        }
        for(int i = low; i <= high; i++)
        {
            v[i] = temp[i - low];
        }
        return cnt;
    }
    int mergesort(int low , int high, vector<int> &v)
    {
        int cnt = 0;
        
        if(low >= high)
            return cnt;
            
        int mid = (low + high)/2;
        
        cnt += mergesort(low, mid, v);
        cnt += mergesort(mid + 1, high, v);
        cnt += merge(low,high,mid,v);
        return cnt;
    }
    void inorder(Node *root, vector<int> &v)
    {
        if(root == NULL)
            return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    int pairsViolatingBST(int n, Node *root) {
        vector<int> v;
        inorder(root,v);
       /* for(int i = 0; i < v.size(); i++)
            cout << v[i] << " ";*/
        return mergesort(0, n-1, v);
        //return cnt;
        // your code goes here
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends