class Solution {
public:
    bool isOdd(int n){
        if(n%2 != 0) return true;
        return false;
    }

    int Solve(vector<int>& nums, int k){
        int n = nums.size();

        int left = 0,right = 0,oddCnt = 0,ans = 0;

        while(right < n){
            if(isOdd(nums[right])) oddCnt++;

            while(oddCnt > k){
                if(isOdd(nums[left])) oddCnt--;
                left++;
            }
            ans+=(right-left+1);

            right++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return Solve(nums,k) - Solve(nums,k-1);
    }
};