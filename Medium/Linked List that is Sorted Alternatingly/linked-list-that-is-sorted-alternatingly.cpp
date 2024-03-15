//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    
    void reverse(Node **head){
        Node *pre = NULL,*cur = *head;
        while(cur){
            Node *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        *head = pre;
    }
    
    Node* merge(Node **r1, Node **r2){
        if(*r1==NULL){
            return *r2;
        }
        if(*r2 == NULL){
            return *r1;
        }
        Node *r = new Node(0);
        Node *ptr = r;
        while(*r1 and *r2){
            if((*r1)->data<(*r2)->data){
                ptr->next = *r1;
                *r1 = (*r1)->next;
            }
            else{
                ptr->next = *r2;
                *r2 = (*r2)->next;
            }
            ptr = ptr->next;
        }
        
        while(*r2){
            ptr->next = (*r2);
            ptr = ptr->next;
            *r2 = (*r2)->next;
        }
        while(*r1){
            ptr->next = (*r1);
            ptr = ptr->next;
            *r1 = (*r1)->next;
        }
        
        if(ptr){
            ptr->next = NULL;
        }
        return r->next;
    }
    
    void sort(Node **head)
    {
        Node *r1 = new Node(0);
        Node *r2 = new Node(0);
        Node * ptr = *head;
        Node *f = r1,*s = r2;
        while(ptr){
            f->next = ptr;
            ptr = ptr->next;
            f = f->next;
            
            if(ptr){
                s->next = ptr;
                s = s->next;
                ptr = ptr->next;
            }
        }
        if(f){
            f->next = NULL;
        }
        if(s){
            s->next = NULL;
        }
        
        reverse(&(r2->next));
        
        *head = merge(&(r1->next),&(r2->next));
        
    }

};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends