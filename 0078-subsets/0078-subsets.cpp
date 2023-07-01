class Solution {
public:

    void prinSubsequence(vector<int>&nums,int n,int index,vector<vector<int>> &ans, vector<int> &output){


        //base condition
        if(index >= n){
            ans.push_back(output);
            return;
        }

        //to pick the element in the subsequence 
        output.push_back(nums[index]);
        prinSubsequence(nums,n,index+1,ans,output);

        //to not pick the element in the subsequence 
        output.pop_back();
        prinSubsequence(nums,n,index+1,ans,output);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int n = nums.size();
        prinSubsequence(nums,n,0,ans,output);
        return ans;
    }
};