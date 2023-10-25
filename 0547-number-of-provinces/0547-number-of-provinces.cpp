class Solution {
public:
    void DFS(int node, vector<int> adjL[],vector<int> &vis) {
        vis[node] = 1;

        for (auto it : adjL[node]) {
            if (!vis[it]) {
                DFS(it, adjL, vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // To convert the adjacency matrix to adjacency list
        vector<int> adjL[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<int> vis(n,0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                DFS(i, adjL, vis);
            }
        }

        return cnt;
    }
};
