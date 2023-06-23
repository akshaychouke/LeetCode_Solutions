class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        int cnt = 0;

        int i=0;
        while(i<sz && cnt <n){
            if(flowerbed[i] == 0){
                int prev,next;
                if(i==0){
                    prev=0;
                }
                else{
                    prev=flowerbed[i-1];
                }

                if(i==sz-1){
                    next=0;
                }
                else{
                    next = flowerbed[i+1];
                }

                if(prev == 0 && next == 0){
                    flowerbed[i] = 1;
                    cnt++;
                }
            }
            i++;
        }
        return cnt == n;
    }
};