class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mpp;

        for(auto it:s){
            mpp[it]++;
        }

        for(auto it:t){
            mpp[it]--;
        }

        for(auto it:mpp){
            if(it.second != 0){
                return it.first;
            }
        }

        return '\0';
    }
};