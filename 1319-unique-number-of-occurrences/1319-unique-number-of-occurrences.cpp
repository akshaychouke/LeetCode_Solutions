class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp1;
        unordered_map<int,bool> mpp2;

        for(auto i:arr){
            mpp1[i]++;
        }

        for(auto i:mpp1){
            int ans = i.second;
            if(mpp2[ans] == true) return false;
            mpp2[ans] = true;
        }

        return true;
    }
};