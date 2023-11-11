class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        // calculating indegree of every node
        vector<int> indegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++){
            for (int adjNode : adj[i]){
                indegree[adjNode]++; 
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
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

        if(topo.size() == numCourses) return topo;
        return {};
    }
};