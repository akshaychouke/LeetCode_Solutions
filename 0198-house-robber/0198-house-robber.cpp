class Solution {
public:
    int Solve(int idx,vector<int>& nums,vector<int> &dp){
        if(idx < 0) return 0;
        if(idx == 0) return nums[0];

        if(dp[idx] != -1) return dp[idx];
        int second = nums[idx] + Solve(idx-2,nums,dp);
        int third = nums[idx] + Solve(idx-3,nums,dp);

        int ans = max(second,third);
        return dp[idx] = ans;
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n+1,-1);

        int first = Solve(n-1,nums,dp);
        int second = Solve(n-2,nums,dp);

        return max(first,second);
    }
};