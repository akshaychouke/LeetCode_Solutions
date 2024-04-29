//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
    int lcs(int i, int j, string &s, string t, vector<vector<int>> &dp) {
      if (i < 0 || j < 0)
        return 0;
    
      if (dp[i][j] != -1)
        return dp[i][j];
    
      if (s[i] == t[j])
        return dp[i][j] = 1 + lcs(i - 1, j - 1, s, t, dp);
    
      return dp[i][j] = max(lcs(i - 1, j, s, t, dp), lcs(i, j - 1, s, t, dp));
    }

	int minOperations(string s1, string s2) 
	{ 
	    // Your code goes here
      int n = s1.length();
      int m = s2.length();
    
      vector<vector<int>> dp(n, vector<int>(m, -1));
    
      int CommanLen = lcs(n - 1, m - 1, s1, s2, dp);
    
      int ans = (n - CommanLen) + (m - CommanLen);
      return ans;
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends