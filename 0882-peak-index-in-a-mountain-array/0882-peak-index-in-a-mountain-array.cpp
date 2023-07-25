class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();

        int ans = 0;

        int i=0,j=n-1;

        while(i<=j){
            int mid = (i+j)/2;

            if(arr[mid] > arr[mid+1] && arr[mid] >  arr[mid-1]){
                ans =  mid;
                break;
            }
            else if(arr[mid] < arr[mid+1]){
                i = mid+1;
            }
            else{
                j = mid - 1;
            }
        }

        return ans;
    }
};