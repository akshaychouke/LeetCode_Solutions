//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    priority_queue<int> MaxHeap;
    priority_queue<int, vector<int>, greater<int>> MinHeap;
    double Median;
    
    // We are sorting it in ascending order, lets say x is median then:
    // MaxHeap...<x<...MinHeap
    
    public:

    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (!MaxHeap.size()) {
            MaxHeap.push(x);
        }
        else if (x < MaxHeap.top()) {
            MaxHeap.push(x);
        } else {
            MinHeap.push(x);
        }
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        int diff = MaxHeap.size() - MinHeap.size();
        if (diff > 1) {
            MinHeap.push(MaxHeap.top());
            MaxHeap.pop();
        }
        else if (diff * -1 > 1) {
            MaxHeap.push(MinHeap.top());
            MinHeap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if (MaxHeap.size() == MinHeap.size()) {
            Median = (MaxHeap.top() + MinHeap.top()) / 2.00;
        }
        else if (MaxHeap.size() > MinHeap.size()) {
            Median = MaxHeap.top();
        }
        else {
            Median = MinHeap.top();
        }
        return Median;
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends