//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int Solve(int ind,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>> &dp){
    int n = prices.size();
    if(ind == n || cap == 0) return 0;
    
    if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    if(buy){
        return dp[ind][buy][cap] = max(-prices[ind]+Solve(ind+1,0,cap,prices,dp),0+Solve(ind+1,1,cap,prices,dp));
    }
    else{
        return dp[ind][buy][cap] = max(prices[ind]+Solve(ind+1,1,cap-1,prices,dp),0+Solve(ind+1,0,cap,prices,dp));
    }
}
int maxProfit(vector<int>&prices){
    //Write your code here..
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
       
        for(int ind=n-1;ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap = 1;cap<=2;cap++){
                        if(buy){
                            dp[ind][buy][cap] = max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
                        }
                        else{
                             dp[ind][buy][cap] = max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                        }                    
                }
            }
        }
        
        return dp[0][1][2];
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends