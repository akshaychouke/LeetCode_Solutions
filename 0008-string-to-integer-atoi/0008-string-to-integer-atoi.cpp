class Solution {
public:
    int myAtoi(string s) {
         int sign=1;
        int result=0;
        int i=0;
        int n=s.length();
        while(i<n && s[i] == ' ')
            i++;
        
        if(i<n && s[i]=='+')
        {
            sign*=1;
            i++;
        }
        else if(i<n && s[i]=='-')
        {
            sign*=-1;
            i++;
        }
        
        
        while(i<n && 0<=(int)s[i]-'0' && (int)s[i]-'0'<=9 )
        {
            
            if(result>INT_MAX/10 || (result==INT_MAX/10 && (int)(s[i]-'0')>INT_MAX%10))
            {
                return result=(sign==1?INT_MAX:INT_MIN);
            }
            result*=10;
            result+=((int)s[i]-'0');
            i++;
        }
        return result*sign;
    }
};