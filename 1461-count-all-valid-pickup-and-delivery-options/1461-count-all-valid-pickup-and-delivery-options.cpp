class Solution {
public:
    int countOrders(int n) {
        int mod = 1000000007;
        int slots = 2 * n;
        long long ans = 1;

        while (slots > 0) {
            long long valid_choices = ((static_cast<long long>(slots) * (slots - 1)) / 2) % mod;
            ans = (ans % mod * valid_choices % mod) % mod;
            slots = slots - 2;
        }
        return static_cast<int>(ans % mod);
    }
};
