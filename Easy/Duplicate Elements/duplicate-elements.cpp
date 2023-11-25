//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
  
    void printArray(int n, vector<int> &arr){
        
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    }
    
    void SortedDuplicates(int n, vector<int> &arr) {
        // code here
        vector<int> ans;
        set<int> st;
        unordered_map<int,int> mpp;
        
        for(int i : arr){
            mpp[i]++;
        }
        
        for(int i=0;i<n-1;i++){
            if(mpp[arr[i]] > 1){
                st.insert(arr[i]);
            }
        }
        
        for(auto i:st)
        {
           ans.push_back(i);
        }
        
        sort(ans.begin(),ans.end());
        
        if(ans.size() != 0){
            printArray(ans.size(),ans);
        }
        else{
            cout<<-1;
        }
        cout<<endl;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        
        obj.SortedDuplicates(n, arr);
        
    }
}

// } Driver Code Ends