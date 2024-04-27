//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
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
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
        vector<int>rev,norm;
        int count = 0;
        Node* temp = head;
        while(temp)
        {
            count++;
            if(count>=m&&count<=n)
            rev.push_back(temp->data);
            else
            norm.push_back(temp->data);
            temp = temp->next;
        }
        reverse(rev.begin(),rev.end());
        vector<int>ans;
        int k = 0,j=0;
        for(int i=0;i<count;i++)
        {
            if(i>=m-1&&i<=n-1)
            {
                ans.push_back(rev[k++]);
            }
            else
            {
                ans.push_back(norm[j++]);
            }
        }
        temp = head;
        for(int i=0;i<ans.size();i++)
        {
            temp->data = ans[i];
            temp = temp->next;
        }
        return head;
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends