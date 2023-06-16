class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        int m = edges[0].size();

        unordered_map<int,int> mpp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mpp[edges[i][j]]++;
            }
        }

        int maxi = INT_MIN;
        int ans = 0;
        for(auto it : mpp){
            if(it.second > maxi){
                ans = it.first;
                maxi = it.second;
            }
        }

        return ans;
    }
};