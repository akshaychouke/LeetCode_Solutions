//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int Solve(int i,int j, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;
        if(i == 0  && j == 0) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = Solve(i-1,j,dp);
        int left = Solve(i,j-1,dp);
        
        return dp[i][j] = up+left;
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        
        vector<vector<int>> dp(a,vector<int>(b,-1));
        
        return Solve(a-1,b-1,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends