//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int nums[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        if(l>h) return -1;
        
        int mid = l+(h-l)/2;
        
        if(nums[mid] == key) return mid;
        
        //to check if left part sorted or not
        if(nums[l]<=nums[mid]){
            if(key >= nums[l] && key <= nums[mid]){
               return search(nums,l,mid-1,key);
            }
            else{
                return search(nums,mid+1,h,key);
            }
        }
        else{
           if(key >= nums[mid] && key <= nums[h]){
              return  search(nums,mid+1,h,key);
           }else{
              return  search(nums,l,mid-1,key);
           } 
        }
        
        return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends