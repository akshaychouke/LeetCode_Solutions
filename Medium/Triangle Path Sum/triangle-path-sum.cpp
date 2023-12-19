//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int Solve(int i,int j,int n,vector<vector<int>> &arr,vector<vector<int>> &dp){
        
        if(i == n-1) return arr[n-1][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int bottom = arr[i][j] + Solve(i+1,j,n,arr,dp);
        int diagonal = arr[i][j] + Solve(i+1,j+1,n,arr,dp);
        
        return dp[i][j] = min(bottom,diagonal);
    }
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        // Code here
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return Solve(0,0,n,triangle,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends