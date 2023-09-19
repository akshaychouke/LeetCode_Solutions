class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mpp;
        int ans = 0;
        for(auto it:nums){
            if(mpp[it]){
                ans = it;
                break;
            }
            mpp[it] = true;
        }

        return ans;
    }
};