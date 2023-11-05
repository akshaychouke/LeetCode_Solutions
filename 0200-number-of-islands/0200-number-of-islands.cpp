class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& grid,vector<vector<int>> &vis){
       int n = grid.size();
       int m = grid[0].size();

        if(row<0 || col<0 || row>=n || col>=m){
            return;
        }
        if(grid[row][col]=='0' || vis[row][col]==1){
            return;
        }       
       
        vis[row][col] = 1;

        //to check top,down,left,right
        dfs(row-1,col,grid,vis);
        dfs(row+1,col,grid,vis);
        dfs(row,col-1,grid,vis);
        dfs(row,col+1,grid,vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};