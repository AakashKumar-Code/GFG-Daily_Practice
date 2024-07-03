//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(Node* head) {
         
    Node* temp = head;       
       // Pointer to traverse the linked list
                     
    Node* prev = nullptr;     
       // Pointer to keep track of the previous node

                   
    while (temp != NULL && temp->next != NULL) {          
           // Traverse the linked list until the end
        if (temp->data != temp->next->data) {                     
               // If current node is not a duplicate
            prev = temp;                                                           
               // Move prev to the current node
            temp = temp->next;                                               
               // Move temp to the next node
            continue;
        }

        while (temp->next != NULL && temp->data == temp->next->data) {     
             // If current node is a duplicate, skip all duplicate nodes
            Node* toDel = temp->next;                                                                    
             // Node to be deleted
            temp->next = temp->next->next;                                                          
             // Skip the duplicate node
            delete toDel;                                                                                             
             // Delete the duplicate node
        }
        Node* toDel = temp;                  
          // Node to be deleted (current node)
 
        if (temp == head) {                    
             // If the current node is the head node, update the head
            head = temp->next;
        } else {
            prev->next = temp->next;    
             // Otherwise, skip the current node
        }

        temp = temp->next;                  
          // Move temp to the next node
        delete toDel;                               
          // Delete the current node
    }

     // Return the updated head of the list
    return head;
}
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends