//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
Node* reverseList(Node* head){
    Node* prev = NULL;

    while(head != NULL){
        Node* forward = head->next;

        head->next = prev;
        prev = head;
        head = forward;
    }

    return prev;
}
bool isPalindrome(Node *head)
{
    // write your code here
    Node *slow = head,*fast = head;

    // find middle of the list
    while(fast->next!= NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    //reverse the half of list

    slow->next = reverseList(slow->next);
    slow = slow->next;

    //compare the right half and left half
    Node* temp = head;

    while(slow != NULL){
        if(slow->data != temp->data) return false;
        slow = slow->next;
        temp = temp->next;
    }

    return true;

}
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends