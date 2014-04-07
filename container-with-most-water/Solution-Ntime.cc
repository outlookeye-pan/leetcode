class Solution {
public:
    int maxArea(vector<int> &height) {
        
        //can also don't use iterator. just define i and j, and use height[i], height[j] to obtain the value in position i and j in the vector
        vector<int>::iterator iter1 = height.begin(), iter1_end = height.end();
        vector<int>::iterator iter2 = height.end()-1;
        int i = 0, j = height.size()-1;
        int maxWater = 0;
        int temp = 0;
        
        while(iter1 != iter2)
        {
           temp = ( (*iter1 < *iter2)? *iter1 : *iter2) * (j-i);
           if(maxWater < temp)
                maxWater = temp;
           if(*iter1 < *iter2)
           {
               iter1++;
               i++;
           }
           else
           {
               iter2--;
               j--;
           }
        } //while
        
        return maxWater;
 
    }
};