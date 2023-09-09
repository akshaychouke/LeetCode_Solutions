class Solution {
public:
    int Solve(vector<int>& nums, int target,vector<int>& dp){
        if(target == 0) return 1;
        if(target < 0) return 0;

        if(dp[target] != -1) return dp[target];
        int res = 0;

        for(int i=0;i<nums.size();i++){
            res = res + Solve(nums,target-nums[i],dp);
        }

        return dp[target] = res;

    }
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target+1,-1);
        dp[0] = 1;
        return Solve(nums,target,dp);
    }
};