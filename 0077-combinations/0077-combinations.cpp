class Solution {
public:
    void Solve(int i,int n,int k,vector<int>&subset,vector<vector<int>>&ans){
        
        if(k == 0){
            ans.push_back(subset);
            return;
        }

        if(i>n) return;

        //to include the element 
        subset.push_back(i);
        Solve(i+1,n,k-1,subset,ans);
        subset.pop_back();  //backtrack

        //not include the element
        Solve(i+1,n,k,subset,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        
        vector<int>subset;
        vector<vector<int>> ans;

        Solve(1,n,k,subset,ans);

        return ans;
    }
};