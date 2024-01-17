//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int getSum(int arr[], int N){
        int sum = 0;
        
        for(int i=0;i<N;i++){
            sum += arr[i];
        }
        return sum;
    }

    int getMaxi(int arr[], int N){
        int maxi = INT_MIN;
        
        for(int i=0;i<N;i++){
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }


    int getRequredTime(int arr[],int N,int cap){
        int days = 1,load = 0;
        
        for(int i=0;i<N;i++){
            if(load + arr[i] > cap){
                days++;
                load = arr[i];
            }else{
                load += arr[i];
            }
        }
        return days;
    }

    int leastWeightCapacity(int arr[], int N, int days) {
        // code here
        int s = getMaxi(arr,N);
        int e = getSum(arr,N);
        int ans = 0;

        while(s <= e){
            int mid = s + (e-s)/2;

            int takeDays = getRequredTime(arr,N,mid);
            if(takeDays <= days){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends