//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q1, int k)
    {
        stack<int>st;
        queue<int>q;
        while(k>0)
        {
            st.push(q1.front());
            q1.pop();
            k--;
        }
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        while(!q1.empty())
        {
           q.push(q1.front());
           q1.pop();
        }
        return q;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends