class Solution {
public:
//this is the apporach 1 usign extra TC

    void Solve(vector<int>& nums,vector<vector<int>> &ans,int index){

        //base condition
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        //
        for(int i=index;i<nums.size();i++){
            //swap the numbers to ensure that every element is at possible position
            swap(nums[i],nums[index]);
            Solve(nums,ans,index+1);
            swap(nums[i],nums[index]); //after coming back from recursion and then making array in its initail form
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        Solve(nums,ans,0);
        return ans;
                
        }
};