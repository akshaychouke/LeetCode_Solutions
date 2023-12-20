//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
 int fun(int i,int arr[],int n,int sum,vector<vector<int>>&dp,long long int k)
      {
         if(i==n)
         {
             if(sum==0)
             {
                 return 1;
             }
             return 0;
         }
         if(dp[i][sum]!=-1)return dp[i][sum];
         int p=0;
          if(sum>=arr[i])
          {
            p=fun(i+1,arr,n,sum-arr[i],dp,k);
          }
         int a=fun(i+1,arr,n,sum,dp,k);
         dp[i][sum]=((a)%k+(p%k))%k;
         return dp[i][sum];
      }
    int perfectSum(int arr[], int n, int sum)
    {
        // Your code goes here
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        long long int k=1e9+7;
        return fun(0,arr,n,sum,dp,k);
    }
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends