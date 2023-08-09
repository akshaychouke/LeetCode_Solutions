class Solution {
public:
//see the neetcode video  https://www.youtube.com/watch?v=lf1Pxg7IrzQ
    bool isValid(vector<int>& nums, int p,int num){
        int i=0,cnt=0;

        while(i < nums.size()-1){
            if(abs(nums[i]-nums[i+1]) <= num ){
                cnt = cnt+1;
                i = i+2;
            }
            else{
                i =i+1;
            }

            if(cnt == p) return true;
        }
        return false;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());

        int start = 0;
        int end = 1000000000;  // 10^9

        int res = 0;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(isValid(nums,p,mid)){
                res = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        return res;


    }
};