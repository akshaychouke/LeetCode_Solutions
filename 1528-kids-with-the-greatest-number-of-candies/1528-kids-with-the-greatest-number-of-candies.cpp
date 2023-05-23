class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> ans;
        int maxi = INT_MIN;

        for(auto candy:candies){
            if(candy >= maxi){
                maxi = candy;
            }
        }

        for(auto candy:candies){
            if(candy+extraCandies >= maxi){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;



    }
};