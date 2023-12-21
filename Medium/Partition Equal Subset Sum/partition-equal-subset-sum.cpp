//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool Solve(int nums[],int target,int ind,vector<vector<int>> &dp){
        //base cases
        if(target == 0) return true;
        if(ind == 0) return (nums[0] == target);

        //check in dp 
        if (dp[ind][target] != -1) return dp[ind][target];

        bool notTake = Solve(nums,target,ind-1,dp);
        bool take = false;

        if(nums[ind] <= target){
            take = Solve(nums,target-nums[ind],ind-1,dp);
        }
        return dp[ind][target] = notTake | take;
    }
    int equalPartition(int n, int nums[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum % 2  != 0) return false;
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
        return Solve(nums,sum/2,n-1,dp);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends