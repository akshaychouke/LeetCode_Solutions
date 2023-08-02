class Solution {
public:

    void Solve(vector<vector<int>> &ans,vector<int>& nums,int index){

        //base case
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        //to take each element
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            Solve(ans,nums,index+1);
            swap(nums[i],nums[index]);  //backtrack
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        Solve(ans,nums,0);
        return ans;
    }
};