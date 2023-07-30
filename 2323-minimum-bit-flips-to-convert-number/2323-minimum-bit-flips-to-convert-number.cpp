class Solution {
public:

    int getSetBits(int n){
        int cnt = 0;

        while(n != 0){
            cnt++;
            n = n&(n-1);
        }

        return cnt;
    }
    int minBitFlips(int start, int goal) {
        
        int ans  =  start^goal;

        return getSetBits(ans);
    }
};