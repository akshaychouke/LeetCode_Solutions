//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n){
        // code here
        if(n==1) return 1;
        if(n==2) return 1;
        
        int f = 1,s=1;
        
        for(int i=3;i<=n;i++){
            int third = f+s % 1000000007;
            
            s = f% 1000000007;
            f = third% 1000000007;
        }
        
        return f% 1000000007;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends