class Solution {
public:
    int maxArea(vector<int> &height) {
        
        vector<int>::iterator iter1 = height.begin(), iter1_end = height.end();
        vector<int>::iterator iter2 = iter1+1;
        
        int maxWater = 0, temp = 0;
        int j;
        
        if(height.size() == 0)
            return 0;
        else
        {
            for(int i = 0; iter1 != iter1_end; i++, iter1++)
            {
                for(j = i+1, iter2 = iter1+1; iter2 != iter1_end; j++, iter2++)
                {
                    temp = ((*iter1<*iter2)? *iter1: *iter2) * (j-i);
                    if(maxWater < temp)
                        maxWater = temp;
                }
            }
        
            return maxWater;
        }
    }
};