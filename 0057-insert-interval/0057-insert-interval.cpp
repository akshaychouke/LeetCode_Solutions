class Solution {
public:
    vector<vector<int>> MergeIntervals(vector<vector<int>>& nums){
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        int start = nums[0][0];
        int end = nums[0][1];

        for(int i=1;i<n;i++){
            int s = nums[i][0];
            int e = nums[i][1];

            if(s<=end){
                end = max(e,end);
            }
            else{
                ans.push_back({start,end});
                start = s;
                end = e;
            }
        }

        ans.push_back({start,end});
        return ans;
    }
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& newInterval) {
        nums.push_back(newInterval);
        return MergeIntervals(nums);
    }
};