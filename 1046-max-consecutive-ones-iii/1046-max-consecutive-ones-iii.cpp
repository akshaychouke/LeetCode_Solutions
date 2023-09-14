class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int left=0,right=0,zeroCnt = 0;
        int ans = INT_MIN;

        while(right < n){
            if(nums[right] == 0) zeroCnt++;

            if(zeroCnt > k){
                if(nums[left] == 0) zeroCnt--;
                left++;
            }

            ans = max(ans,right-left+1);
            right++;
        }

        return ans;
    }
};