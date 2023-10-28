//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool DFS(int node,vector<int> adj[],int dfsVis[],int vis[]){
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                bool ans = DFS(it,adj,dfsVis,vis);
                if(ans) return true;
            }
            else if(dfsVis[it]){
                return true;
            }
        }
        dfsVis[node] = 0;
        return false;

    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V] = {0};
        int dfsVis[V] = {0};
        
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                bool ans = DFS(i,adj,dfsVis,vis);
                if(ans) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends