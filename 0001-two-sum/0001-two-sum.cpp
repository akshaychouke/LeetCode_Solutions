class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        map<int,int> mpp;

        for(int i=0;i<n;i++){
            int ele = nums[i];
            int more = target - ele;

            if(mpp.find(more) != mpp.end()){
                ans.push_back(i);
                ans.push_back(mpp[more]);
            }

            mpp[ele] = i;
        }
        return ans;
    }
};