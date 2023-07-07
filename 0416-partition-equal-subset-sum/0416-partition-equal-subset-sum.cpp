class Solution {
public:
    bool Solve(vector<int>& nums,int target,int ind,vector<vector<int>> &dp){
        //base cases
        if(target == 0) return true;
        if(ind == 0) return (nums[0] == target);

        //check in dp 
        if (dp[ind][target] != -1) return dp[ind][target];

        bool notTake = Solve(nums,target,ind-1,dp);
        bool take = false;

        if(nums[ind] <= target){
            take = Solve(nums,target-nums[ind],ind-1,dp);
        }


        return dp[ind][target] = notTake | take;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto it : nums){
            sum+=it;
        }
        if(sum % 2  != 0) return false;
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
        return Solve(nums,sum/2,n-1,dp);
    }
};