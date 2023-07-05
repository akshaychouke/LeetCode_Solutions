class Solution {
public:

    int Solve(int m,int n,vector<vector<int>> &dp){

        //base case 
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        //checl in dp
        if(dp[m][n] != -1) return dp[m][n];

        int up = Solve(m-1,n,dp);
        int left = Solve(m,n-1,dp);

        return dp[m][n] = up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));

        return Solve(m-1,n-1,dp);
    }
};