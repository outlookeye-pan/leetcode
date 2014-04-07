class Solution {
public:
    int romanToInt(string s) {
        
        int number = 0;
        int i = 0;
        
        while(i < s.size())
        {
            //thousand
            if(s[i] == 'M')
            {
                number += 1000;
                i++;
                continue;
            }
            //hundred
            if(s[i] == 'D')
            {
                number += 500;
                i++;
                continue;
            }
            if(s[i] == 'C')
            {
                if(s[i+1] == 'M')
                {
                    number += 900;
                    i = i+2;
                    continue;
                }
                if(s[i+1] == 'D')
                {
                    number += 400;
                    i = i+2;
                    continue;
                }
                else
                {
                    number += 100;
                    i++;
                    continue;
                }
            }

            //ten
            if(s[i] == 'L')
            {
                number += 50;
                i++;
                continue;
            }
            if(s[i] == 'X')
            {
                if(s[i+1] == 'C')
                {
                    number += 90;
                    i = i+2;
                    continue;
                }
                if(s[i+1] == 'L')
                {
                    number += 40;
                    i = i+2;
                    continue;
                }
                else
                {
                    number += 10;
                    i++;
                    continue;
                }
            }

            //less than ten
            if(s[i] == 'V')
            {
                number += 5;
                i++;
                continue;
            }
            if(s[i] == 'I')
            {
                if(s[i+1] == 'X')
                {
                    number += 9;
                    i = i+2;
                    continue;
                }
                if(s[i+1] == 'V')
                {
                    number += 4;
                    i = i+2;
                    continue;
                }
                else
                {
                    number += 1;
                    i++;
                    continue;
                }
            }
    
        } //while
        return number;
    }
};