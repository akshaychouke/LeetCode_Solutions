class Solution {
public:
    int Solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){

        //base case
        if(i == 0 && j == 0) return 1;
        if(i<0 || j<0 || grid[i][j] == 1) return 0;

        //check in dp
        if(dp[i][j] != -1) return dp[i][j];

        int up =0,left = 0;

        up = Solve(i-1,j,grid,dp);
        left = Solve(i,j-1,grid,dp);

        return dp[i][j] = up+left;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();


        if(grid[0][0] == 1) return 0;
        vector<vector<int>> dp(row,vector<int>(col,-1));

        return Solve(row-1,col-1,grid,dp);
    }
};