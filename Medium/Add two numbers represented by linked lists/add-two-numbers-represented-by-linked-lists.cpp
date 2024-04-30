//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // first we will be traversing the entire linked list num1 and store the 
        // digits present in that in a string n1
        struct Node* temp1 = num1;
        string n1 = "";
        while( temp1 != NULL){
            n1 += (char)(temp1 -> data + '0');
            temp1 = temp1 -> next;
        }
        
        // then we will traverse the linked list num2 and store the digits present 
        // in that in another string n2
        string n2 = "";
        struct Node* temp2 = num2;
        while( temp2 != NULL){
            n2 += (char)(temp2 -> data + '0');
            temp2 = temp2 -> next;
        }
        
        // find the last indexes of n1 and n2
        
        int i= n1.size()-1;
        int j = n2.size()-1;
        
        
        // initialize carry as 0, whenever there will bne a carry during addition this will be updated 
        int carry = 0;
        // initialize an empty string as ans for storing the summation of the two strings 
        string ans = "";
        
        // Traversing both the string from behind we will be calculating the sum of the digits occuring in 
        // both the strings 
        while(i>=0 || j>=0){
            // initializing d1 and d2 with 0 which stores the corresponding digits occuring in both the strings
            int d1 = 0;
            int d2 = 0;
            
            // update the values of the d1 and d2 with the corresponding values in n1 and n2
            if( i>=0) d1 = n1[i--]-'0';
            if( j>=0) d2 = n2[j--]-'0';
            
            // calculate their sum and add carry to it
            int sum = d1 + d2 + carry;
            // if the sum comes greater than or equal to 10 then carry needs to be updated
            // and sum will only take the last digit 
            if( sum >= 10){
                carry = sum/10;
                sum = sum%10;
            }else{
                // if the sum is less than 10, carry will be 0 only
                carry = 0;
            }
            
            // every time add the sum to the ans string 
            ans = (char)(sum+'0') + ans;
        }
        
        // if in the end there is some carry left then add that to the ans string 
        if( carry > 0){
            ans = (char)(carry+'0') + ans;
        }
        
        // if the ans string contains only one digit in it, just make a node and return that
        if( ans.size() == 1){
            Node* head = new Node(ans[0]-'0');
            return head;
        }
        
        //  make a dummy node and we will be adding node in sequence to this dummy node
        Node* head = new Node(-1);
        Node* temp = head;
        // keep a flag variable as 0, this will be set to 1 as soon as we get a non zero digit in the ans string
        bool flag =0;
        // traverse the entire ans string 
        for(int k=0;k<=ans.size()-1;k++){
            // till the time 0 occurs, just skip that, as in ans linked list we dont need preceeding 0's
            if(ans[k]-'0' == 0 && flag ==0){
                continue;
            }
            // once we got a non zero entry, we set the flag to 1 
            flag =1;
            // keep on creating the nodes and add them to the linked list to be returned
            temp -> next = new Node(ans[k]-'0');
            temp = temp -> next;
        }
        
        // if after whole traversal, the flag value is 0, that means there were no non zero values in string 
        // just make a node with value equal to 0 and return 
        if( flag == 0){
            Node*head1 = new Node(0);
            return head1;
        }
        
        temp -> next = NULL;
        // otherwise return the head -> next, because head is pointing at dummy node (-1),
        // and we have connected the nodes after this dummy node
        return head -> next;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends