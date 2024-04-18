//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
    void solve(int arr[], int n,int i,int sum,int sm,int &mini,vector<vector<int>> &dp){
        if(i>=n) return;
        
        if(dp[i][sum] != -1){
            return;
        }
        
        int diff = abs(sum - sm);
        mini = min(mini,abs(diff-sum));
        
        solve(arr,n,i+1,sum+arr[i],sm,mini,dp);
        solve(arr,n,i+1,sum,sm,mini,dp);
        
        dp[i][sum] = mini;
    }
    
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sm = 0;
	    for(int i=0;i<n;i++){
	        sm += arr[i];
	    }
	    int mini = INT_MAX;
	    vector<vector<int>> dp(n+1,vector<int>(sm+1,-1));
	    
	    solve(arr,n,0,0,sm,mini,dp);
	    
	    return mini;
	    
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends