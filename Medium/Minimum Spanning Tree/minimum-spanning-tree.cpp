//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int> mst(V,0);
        vector<int> dist(V,INT_MAX);
        
        dist[0] = 0;
        
        for(int i=0;i<V-1;i++){
            
            int mini = INT_MAX;
            int u;
            for(int v=0;v<V;v++){
                if(mst[v] == 0 && dist[v] < mini){
                    mini = dist[v];
                    u = v;
                }
            }
            
            mst[u] = 1;
            
            for(auto it : adj[u]){
                int v = it[0];
                int wt = it[1];
                
                if(mst[v] == 0 && wt < dist[v]){
                    dist[v] = wt;
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<V;i++){
            ans += dist[i];
        }
        
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends