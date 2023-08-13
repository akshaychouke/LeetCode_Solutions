class Solution {
public:
    bool isValid(int i,vector<int>& nums,vector<int> &dp){
        int n = nums.size();
        if(i >= n) return true;

        if(dp[i] != -1) return dp[i];

        bool res = false;

        if(i < n-1 && nums[i] == nums[i+1]){
            res = isValid(i+2,nums,dp);
        }

        if(i < n-2){
            if((nums[i] == nums[i+1] && nums[i+1] == nums[i+2]) || (nums[i]+1 == nums[i+1] && nums[i+1] == nums[i+2]-1)){
                res = res || isValid(i+3,nums,dp);
            }
        }

        dp[i] = res;
        return res;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return isValid(0,nums,dp);
    }
};