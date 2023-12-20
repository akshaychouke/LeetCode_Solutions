//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool Solve(vector<int> arr, int sum, int ind, vector<vector<int>> &dp) {
      // base case
      if (sum == 0)
        return true;
      if (ind == 0)
        return (arr[0] == sum);
    
      // check in dp
      if (dp[ind][sum] != -1)
        return dp[ind][sum];
    
      bool notTake = Solve(arr, sum, ind - 1, dp);
      bool take = false;
      if (arr[ind] <= sum) {
        take = Solve(arr, sum - arr[ind], ind - 1, dp);
      }
    
      return dp[ind][sum] = take | notTake;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n, vector < int > (sum + 1, -1));
        
        return Solve(arr,sum,n-1,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends