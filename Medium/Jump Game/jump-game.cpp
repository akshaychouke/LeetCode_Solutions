//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    bool Solve(int arr[],int ind,int n){
        if(ind >= n-1) return true;
        
        if(arr[ind] == 0 && ind != n-1) return false;
        
        int res = false;
        
        for(int i=1;i<=arr[ind];i++){
            res = Solve(arr,ind+i,n);
            
            if(res) break;
        }
        
        return res;
    }
    int canReach(int A[], int N) {
        // code here
        
        return Solve(A,0,N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends