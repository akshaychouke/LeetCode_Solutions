//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int i, int j, int n, int m, vector<vector<int>> &grid) {
    return (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1);
    }
    
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m  = grid[0].size();
        
        queue<pair<int,int>> q;
        
        int ans = 0,fresh = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] ==2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) fresh++;
            }
        }
        
        
        while(!q.empty()){
            int temp = 0;
            int q_size = q.size();
            
            while(q_size != 0){
                pair<int,int> node = q.front();
                q.pop();
                
                int x1 = node.first;
                int y1 = node.second;
                
                int ax[4] = {1, -1, 0, 0};
                int ay[4] = {0, 0, 1, -1};
                
                for(int i=0;i<4;i++){
                    int x = x1+ax[i];
                    int y = y1+ay[i];
                    
                    if(isValid(x,y,n,m,grid)){
                        temp++;
                        q.push({x,y});
                        grid[x][y] =2;
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

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends