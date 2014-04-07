#define min_integer -2147483648
#define max_integer 2147483647
class Solution {
public:
    int reverse(int x) {
        long rv_integer = 0;
        int pos_value = 0;
        pos_value = (x<0)?(-x):x;
        
        do
        {
            rv_integer = pos_value%10 + rv_integer*10;
            pos_value = pos_value/10;
        } while((pos_value% 10 != 0) || (pos_value/10 != 0));
        
        if(x<0)
        {
            if(-rv_integer < min_integer)
                return min_integer;
            else
            {
                return -rv_integer;
            }
        }
        else
        {
            if(rv_integer > max_integer)
                return max_integer;
            else
                return rv_integer;
        }
    }
};