class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());

        int n = arr.size();
        int m = arr[0].size();

        int start = arr[0][0],end=arr[0][1];
        int cnt = 0;
        for(int i=1;i<n;i++){
            int s=arr[i][0];
            int e=arr[i][1];
            if(s<end){
                cnt++;
                start=min(start,s);
                end = min(end,e);
            }
            else{
                start=min(start,s);
                end = max(end,e);                
            }
        }

        return cnt;
    }
};