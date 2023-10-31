class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();

        int res = 0;
        vector<int> ans;

        for(int i=0;i<n;i++){
            int temp = res^pref[i];
            ans.push_back(temp);

            res = res^temp;
        }

        return ans;
    }
};