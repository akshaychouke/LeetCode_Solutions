class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0,right = 0,end = s.length()-1;
        unordered_map<char,int> mpp;
        int ans = 0;
        while(right != s.length()){
            mpp[s[right]] +=1;
            while(mpp['a'] && mpp['b'] && mpp['c']){
                ans += 1 + (end-right);
                mpp[s[left]]-= 1;
                left++;
            }
            right++;
        }

        return ans;
    }
};