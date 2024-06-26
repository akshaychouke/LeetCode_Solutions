//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        if(n <= 1) return 0;
        long long ans = 0;
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        
        for(long long i=0;i<n;i++){
            pq.push(arr[i]);
        }
        
        while(!pq.empty()){
            long long n1 = pq.top();
            pq.pop();
            long long n2 = pq.top();
            pq.pop();
            
            long long sum = n1 + n2;
            ans += sum;
            if(!pq.empty()){
                pq.push(sum);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends