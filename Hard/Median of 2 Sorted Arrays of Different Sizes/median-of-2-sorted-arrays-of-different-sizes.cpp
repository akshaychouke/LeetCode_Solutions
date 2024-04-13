//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        // Your code goes here
        int n = arr1.size();
        int m = arr2.size();
        vector<int> temp;
        int i = 0,j = 0;
        
        while(i<n && j < m){
            if(arr1[i] <= arr2[j]){
                temp.push_back(arr1[i]);
                i++;
            }else{
                temp.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i<n){
                temp.push_back(arr1[i]);
                i++; 
        }
        
        while(j<m){
            temp.push_back(arr2[j]);
            j++;            
        }
        
        int size = temp.size();
        if(size % 2 != 0){
            return (double)temp[size/2];
        }
        int mid = size/2;
        return ((double)temp[mid] + (double)temp[mid-1])/2;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends