//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int rec(int i, int j, int *arr){
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
            
        int mini = INT_MAX;
        for(int k = i; k <= j-1; k++){
            int temp = rec(i,k,arr) + rec(k+1,j,arr) + arr[i-1]*arr[k]*arr[j];
            mini = min(mini, temp);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(int N, int arr[])
    {
        dp.resize(N,vector<int>(N,-1));
        return rec(1,N-1,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends