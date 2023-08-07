class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();

        int start = 0;
        int end = (m*n)-1;

        int mid = (start+end)/2;

        while(start <= end){
            int num = mat[mid/n][mid%n];

            if(num == target) return true;
            else if(num < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }

            mid = (start+end)/2;
        }

        return false;
    }
};