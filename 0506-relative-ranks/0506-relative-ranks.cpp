class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        vector<string> ans;
        unordered_map<int,string> mpp;
        priority_queue<int> pq;

        for(auto it :score){
            pq.push(it);
        }

        int rank = 1;
        while(pq.size()){
            int topper = pq.top();
            if(rank == 1){
                mpp[topper] = "Gold Medal";
            }
            else if(rank == 2){
                mpp[topper] = "Silver Medal";
            }
            else if(rank == 3){
                mpp[topper] = "Bronze Medal";
            }
            else{
                mpp[topper] = to_string(rank);
            }
            rank++;
            pq.pop();
        }

        for(auto it:score){
            ans.push_back(mpp[it]);
        }

        return ans;

    }
};