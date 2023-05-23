class Solution {
public:
    bool isVowel(char c) const{
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string reverseVowels(string s) {
        
        int i=0,j = s.size()-1;

        while(i<j){
            if(i<j && !isVowel(s[i])){
                i++;
            }
            if(i<j && !isVowel(s[j])){
                j--;
            }

            if(i<j && isVowel(s[i]) && isVowel(s[j])){
                swap(s[i],s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};