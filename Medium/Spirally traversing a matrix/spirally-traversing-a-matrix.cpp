//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int n, int m) 
    {
        // code here 
        vector<int> ans;
        int dir = 0;
        int top = 0;
        int left = 0;
        int right = m - 1;
        int bot = n-1;
        
        while(top <= bot && left <= right){
            
            if(dir == 0){   // from left to right in top row
            
                for(int i = left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
                
            }else if(dir == 1){   // from top to bottom in right col
                
                for(int i=top;i<=bot;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
                
            }else if(dir == 2){   //from right to left in bot row
                
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bot][i]);
                }
                bot--;
                
            }else{          // from bottom to top in left col
                
                for(int i = bot;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            
            dir++;
            dir = dir%4;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends