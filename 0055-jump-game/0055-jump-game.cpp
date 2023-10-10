class Solution {
public:
    bool Solve(int idx,vector<int>& nums,vector<int>& dp){
        if(idx == nums.size()-1) return true;
        if(nums[idx] == 0) return false;

        if(dp[idx] != -1) return dp[idx];
        bool ans = false;
        for(int i=1;i<=nums[idx];i++){
            ans = Solve(idx+i,nums,dp);
            if(ans) break;
        }

        return dp[idx] = ans;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return Solve(0,nums,dp);
    }
};