
class Solution {
public:
    string convert(string s, int nRows) {
        int len = s.length();
        char array[nRows][len];
        memset(array, 0, sizeof(array));
        int pt = 0;
        string newstring;
        if(nRows <= 1)
            return s;
        else
        {
            for(int column = 0; column < len; column++)
            {
                for(int row = 0; row < nRows; row++)
                {
                    if(pt < len)
                    {
                        if(column % (nRows-1) == 0)
                        {
                            array[row][column] = s[pt];
                            pt++;
                        }
                        else
                        {
                            if((row+column)%(nRows-1) == 0)
                            {
                                array[row][column] = s[pt];
                                pt++;
                            }
                        }
                    }
                } //for row loop
            } //for column loop
       
            for(int row = 0; row < nRows; row++)
            {
                for(int column = 0; column < len; column++)
                {
                    if(array[row][column] != 0)
                    {
                        newstring += array[row][column];
                    }
                }
            }
            return newstring;
        } //else nRows > 1
    }
};