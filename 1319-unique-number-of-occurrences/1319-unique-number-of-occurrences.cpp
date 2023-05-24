class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mpp1;
        set<int> s;

        for(auto i:arr){
            mpp1[i]++;
        }

        for(auto i:mpp1){
            int ans = i.second;
            s.insert(ans);
        }

        //if they are unique numbers of occurences then set and map will have same size
        return s.size() == mpp1.size();
    }
};