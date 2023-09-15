class Solution {
public:
    int Solve(vector<int>& nums, int goal){
        int n = nums.size();
        int left = 0,right=0;
        int sum = 0,ans = 0;
        if (goal < 0)
            return 0;
        for(right=0;right<n;right++){
            sum+=nums[right];
            while(sum > goal){
                sum -= nums[left++];
            }
            ans += right-left+1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return Solve(nums,goal) - Solve(nums,goal-1);
    }
};