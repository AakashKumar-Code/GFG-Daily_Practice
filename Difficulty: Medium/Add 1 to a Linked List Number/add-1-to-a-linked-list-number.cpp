//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  
    Node* reverse(Node* head){
        Node* prev=NULL, *node=head;
        while(node!=NULL){
            Node* tmp=node->next;
            node->next=prev;
            prev=node;
            node=tmp;
        }
        return prev;
    }
    const int mod=1e9+7;
  
    Node* addOne(Node* head) {
        // Your Code here
        // return head of list after adding one
        if(!head){
            Node* newH=new Node(1);
            return newH;
        }
        Node* tail=reverse(head);
        int c=1;
        Node* node=tail;
        while(node!=NULL && c>0){
            int v=(node->data+c)%mod;
            node->data=(v%10);
            c=v/10;
            node=node->next;
        }
        Node* prevH=reverse(tail);
        if(c>0){
            Node* newH=new Node(1);
            newH->next=prevH;
            return newH;
        }else return prevH;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends