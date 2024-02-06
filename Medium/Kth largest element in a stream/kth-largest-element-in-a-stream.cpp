//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        // code here
        priority_queue<int> q;
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int val = arr[i];
            
            if(q.size()<k) {
                q.push(-val);
            }
            else {
                if(-q.top()<val) {
                    q.pop();
                    q.push(-val);
                }
            }
            q.size() < k ? ans.push_back(-1) : ans.push_back(-q.top());
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,n;
        cin>>k>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> v = ob.kthLargest(k,arr,n);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends