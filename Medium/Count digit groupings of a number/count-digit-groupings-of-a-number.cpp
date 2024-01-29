//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
int calc(int i, int prev, string &str, vector<vector<int>>&dp)
	{
	    if(i == str.size())
	        return 1;
	     if(dp[i][prev] != -1)
	        return dp[i][prev];
	     int sum = 0, ans =0;
	     for(int j=i;j<str.size();++j)
	     {
	         sum += stoi(str.substr(j,1));
	         if(sum >= prev)
	            ans += calc(j+1,sum,str,dp);
	     }
	     return dp[i][prev] = ans;
	      
	}
	int TotalCount(string str){
	    // Code here
	    int sum = 0, n = str.size();
	    for(int i = 0; i<n ;++i)
	    {
	        sum += stoi(str.substr(i,1));
	    }
	    vector<vector<int>>dp(n,vector<int>(sum+1,-1));
	    int ans = 0;
	    sum = 0;
	    for(int i =0;i<n;++i)
	    {
	        sum += stoi(str.substr(i,1));
	        ans += calc(i+1,sum,str,dp);
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends