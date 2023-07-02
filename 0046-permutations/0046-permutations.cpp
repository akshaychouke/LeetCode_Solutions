class Solution {
public:
//this is the apporach 1 usign extra TC

    void Solve(vector<int>& nums,vector<vector<int>> &ans,vector<int>& ds,int mpp[]){

        //base condition
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(mpp[i] != 1){
             //to select element which is not selected and push in ds and mark true
                ds.push_back(nums[i]);
                mpp[i] = 1;
                Solve(nums,ans,ds,mpp);  //recursive call 

                // mark the element to 0 ans remove from ds for next permutation 
                mpp[i] = 0; 
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int mpp[nums.size()];

        for(auto i : mpp){
            i = 0;
        }

        Solve(nums,ans,ds,mpp);

        return ans;
    }
};