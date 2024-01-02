//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends

class Solution
{
    public:
    void merge(int arr[], int l, int mid, int r)
    {
         // Your code here
         int len1 = mid-l+1;
         int len2 = r-mid;
         
         int *first = new int[len1];
         int *second = new int[len2];
         
         int mainIndex = l;
         for(int i=0;i<len1;i++){
           first[i] = arr[mainIndex++];  
         }
         mainIndex = mid+1;
         for(int i=0;i<len2;i++){
           second[i] = arr[mainIndex++];  
         }
         
         int index1 = 0 , index2 = 0;
         mainIndex = l;
         
         while(index1 < len1 && index2 < len2){
             if(first[index1] < second[index2]){
                 arr[mainIndex++] = first[index1++];
             }
             else{
                 arr[mainIndex++] = second[index2++];
             }
         }
         
         while(index1 < len1){
             arr[mainIndex++] = first[index1++];
         }
         
         while(index2 < len2){
             arr[mainIndex++] = second[index2++];
         }
         
         delete []first;
         delete []second;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l >= r) return;
        
        int mid = l + (r - l) / 2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
    }
};


//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends