class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool flag1 = true;

        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]){
                flag1=false;
                break;
            }
        }

        bool flag2 = true;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i-1] < nums[i]){
                flag2 = false;
                break;
            }
        }

        return flag1 || flag2;
    }
};