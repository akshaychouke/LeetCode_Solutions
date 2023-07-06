class Solution {
public:
    int Solve(vector<vector<int>>& triangle,int i,int j,vector<vector<int>>&dp){

        //base case
        int n = triangle.size();
        if(i == n-1) return triangle[n-1][j];

        if(dp[i][j] != -1) return dp[i][j];


        int down = triangle[i][j] + Solve(triangle,i+1,j,dp);
        int diagonal = triangle[i][j] + Solve(triangle,i+1,j+1,dp);

        return dp[i][j] = min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return Solve(triangle,0,0,dp);
    }
};