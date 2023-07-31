class Solution {
public:
    double myPow(double x, long long n) {

        double ans = 1.0;
        if(n<0){
            x = 1/x;
            n = -n;
        }

        while(n > 0){
            if(n&1){
                ans = ans*x;
            }
            x = x*x;
            n = n>>1;
        }

        return ans;
    }
};
