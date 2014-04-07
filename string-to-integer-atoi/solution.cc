
class Solution {
public:
    int atoi(const char *str) {
        int len = strlen(str);
        long long output = 0;
        int neg_flag = 0; // if negative, set to 1.
        
        if (str == NULL)
            return 0;
        else
        {
            for(int i = 0; i<len; i++)
            {
                if(str[i] >= '0' && str[i] <= '9') //convert to number
                {
                    output = str[i] - '0' + output*10;
                }
                else if(str[i] == '-' && output == 0 && (str[i+1] >= '0' && str[i+1] <= '9'))
                {
                    neg_flag = 1;
                }
                else if((str[i] == '-' || str[i] == '+') && output == 0 && (str[i+1] < '0' || str[i+1] > '9'))
                {
                    break;
                }
                else
                {
                    if(output != 0 || (str[i-1] >= '0' && str[i-1] <= '9'))
                        break;
                }
            } //for
            if(neg_flag == 1)
                output = -output;
        } //str is not empty
        
        if(output < INT_MIN)
            return INT_MIN;
        else if(output > INT_MAX)
            return INT_MAX;
        else
            return output;
    }
};