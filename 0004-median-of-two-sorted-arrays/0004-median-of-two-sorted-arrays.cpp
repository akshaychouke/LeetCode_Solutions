class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        
        double mean = 0;
        
        vector<int> v;        
        
	    v.insert(v.end(), nums1.begin(), nums1.end());
        v.insert(v.end(), nums2.begin(), nums2.end());
        
        sort(v.begin(),v.end());
        
        int sz = v.size();
        
        int s = 0;
        int e = sz-1;
            
        int mid = (s+e)/2;
        
        if(sz%2==0){
            
            double sum = v[mid] + v[mid+1];
            mean = sum/2;
        }
        else{
            
            mean = v[mid];
        }
        
        return mean;
        
    }
};