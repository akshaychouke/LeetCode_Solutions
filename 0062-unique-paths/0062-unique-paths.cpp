class Solution {
public:
    int Solve(int a,int b,vector<vector<int>> &dp){
        if(a < 0 || b < 0) return 0;
        if(a == 0 && b == 0) return 1;

        if(dp[a][b] != -1) return dp[a][b];

        int up = Solve(a-1,b,dp);
        int left = Solve(a,b-1,dp);

        return dp[a][b] = up+left;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return Solve(m-1,n-1,dp);
    }
};