class Solution {
public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>> &grid) {
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m  = grid[0].size();

        queue<pair<int,int>> q;
        int ans = 0,fresh = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    //push in the queue
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }


        while(!q.empty()){
            int temp = 0;
            int q_size  = q.size();

            while(q_size != 0){

                pair<int,int> node = q.front();
                q.pop();

                int x1 = node.first;
                int y1 = node.second;

                int ax[4] = {1, -1, 0, 0};
                int ay[4] = {0, 0, 1, -1};

                for(int i=0;i<4;i++){

                    int x = ax[i] + x1;
                    int y = ay[i] + y1;

                    if(isValid(x,y,n,m,grid)){
                        temp++;
                        grid[x][y] = 2;
                        q.push({x,y});
                    }
                }
                q_size--;
            }

            if(temp != 0) ans++;
        }


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
            }
        }
        
        return ans;
    }
};