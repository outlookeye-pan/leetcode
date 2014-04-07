class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        
        if(p == NULL || s == NULL || *p == '*') return false;
        if(*p == '\0') return *s == '\0';
        
        if(*(p+1) != '*')
        {
            if(*s==*p || (*p == '.' && *s != '\0') )
                return isMatch(s+1, p+1);
            else
                return false;
        }
        else
        {
            //recursive to check x*. Since we don't know how many times to repeat the letter before *, so use recursive
            while(*s==*p || (*p == '.' && *s != '\0'))
            {
                if(isMatch(s, p+2))
                    return true;
                s++;
            }
            //
            return isMatch(s,p+2);
        }
    }
};