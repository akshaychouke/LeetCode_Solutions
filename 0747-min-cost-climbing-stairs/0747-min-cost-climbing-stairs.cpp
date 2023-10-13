class Solution {
public:
    int Solve(int idx,vector<int>& cost,vector<int> &dp){
        if(idx < 0) return 0;
        if(idx == 0) return cost[0];

        //check in dp
        if(dp[idx] != -1) return dp[idx];

        int first = 0,second = 0;

        first = cost[idx] + Solve(idx-1,cost,dp);
        second = cost[idx] + Solve(idx-2,cost,dp);

        return dp[idx] = min(first,second);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);

        int n1 = Solve(n-1,cost,dp);
        int n2 = Solve(n-2,cost,dp);

        return min(n1,n2);
    }
};