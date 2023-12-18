//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
    int Solve(vector<int>&arr,int ind,vector<int> &dp){
        if(ind == 0) return arr[ind];
         if(ind < 0) return 0;
    
         if(dp[ind] != -1) return dp[ind];
         
         int pick = arr[ind] + Solve(arr,ind-2,dp);
         int notPick = 0 + Solve(arr,ind-1,dp);
         
         return dp[ind] = max(pick,notPick);
         
    }
    
	int findMaxSum(vector<int>&arr, int n) {
	    // code here
        vector<int> dp(n,-1);
        return Solve(arr,n-1,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends