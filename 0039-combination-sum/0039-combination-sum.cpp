class Solution {
public:

    void Solve(vector<int>& candidates,int n,int target,int indx,vector<int>& output,vector<vector<int>> &ans){

        //base case 
        if(indx == n){
            if(target == 0){
                ans.push_back(output);
            }
            return;
        }

        //to take the element in the combination
        bool check = candidates[indx] <= target;   //if the sum is grater than current element then we can puck it

        if(check){
        output.push_back(candidates[indx]);
        target = target - candidates[indx];
        Solve(candidates,n,target,indx,output,ans);
        //when come back from recursion remove the element and add the current elment in the target
        target += candidates[indx];
        output.pop_back();
        }

        Solve(candidates,n,target,indx+1,output,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> output;
        int sum = 0;
        int n = candidates.size();
        Solve(candidates,n,target,0,output,ans);

        return ans;
        
    }
};