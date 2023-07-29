class Solution {
public:
    int getCount(uint32_t n) {
        int cnt = 0;
        
        while(n != 0){
            n = n&n-1;
            cnt++;
        }

        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i=0;i<=n;i++){
            int nums = getCount(i);
            ans.push_back(nums);
        }
        return ans;
    }
};