//Approach-3 (BOttom UP : DP)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> t(n+1, n+2);
        
        //t[i] = minimum taps needed to cover 0 to ith of Garden
        t[0] = 0; //I need 0 tap to cover 0 to 0
        
        //Why start from i = 0
        //Because value at ranges[0] also impacts the range {i-ranges[i], i+ranges[i]}
        //We will miss that impact if we skip i = 0
        for(int i = 0; i<n+1; i++) {
            
            int l = max(0, i-ranges[i]);
            int r = min(n, i+ranges[i]);
            
            /*
                0 to l is watered
                We now need to find minimum taps to cover from (l+1) to r
            */
            for(int j = l+1; j<=r; j++)
                
                /*
                    Check if this range from(left+1..right) can
                    be watered using less number of taps than previous
                */
                
                t[j] = min(t[j], t[l]+1);
            
        }
        
        //if min taps needed to water ground is greater than (n+1) we return -1
        //Because we only had (n+1) taps
        return t[n] > n+1 ? -1 : t[n];
    }
};