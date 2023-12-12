//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int dfs(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i<0 or i>=n or j<0 or j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=grid[i][j]+max({dfs(i-1,j+1,n,m,grid,dp),dfs(i+1,j+1,n,m,grid,dp),dfs(i,j+1,n,m,grid,dp)});
    }
    int maxGold(int n, int m, vector<vector<int>> grid)
    {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int maxi=-1;
        for(int i=0;i<n;i++){
            int d=dfs(i,0,n,m,grid,dp);
            maxi=max(maxi,d);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends