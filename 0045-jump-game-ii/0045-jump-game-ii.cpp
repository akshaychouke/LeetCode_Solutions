class Solution {
public:
    int Solve(int idx,vector<int>& nums,vector<int>& dp){
        if(idx == nums.size()-1) return 0;
        

        if(dp[idx] != INT_MAX-1) return dp[idx];

        for(int i=1;i<=nums[idx];i++){
            if(idx+i < nums.size()){
                int ans = Solve(idx+i,nums,dp)+1;
                dp[idx] = min(dp[idx],ans);
            }
        }

        return dp[idx];
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),INT_MAX-1);

        return Solve(0,nums,dp);
    }
};