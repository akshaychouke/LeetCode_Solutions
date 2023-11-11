class Solution {
public:
    bool kahnAlgo(int V,vector<int> adj[]){
        // calculating indegree of every node
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++){
            for (int adjNode : adj[i]){
                indegree[adjNode]++; 
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);  //push nodes which are having 0 indegree
            }
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(int it:adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(topo.size() == V) return true;
        return false;


    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }

        return kahnAlgo(numCourses,adj);
    }
};