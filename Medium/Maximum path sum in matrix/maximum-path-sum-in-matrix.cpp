//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int Solve(int i,int j,int n,vector<vector<int>> &arr,vector<vector<int>> &dp){
        
        if(i >= n || j >= n || j < 0 || i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = arr[i][j] + max({Solve(i+1,j,n,arr,dp),Solve(i+1,j-1,n,arr,dp),Solve(i+1,j+1,n,arr,dp)});
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(N,-1));
        int maxi = 0;
        
        for(int i=0;i<N;i++){
            int temp = Solve(0,i,N,Matrix,dp);
            maxi = max(maxi,temp);
        }
        
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends