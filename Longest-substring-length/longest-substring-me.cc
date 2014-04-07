class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //int visited[26] = {-1}; it's wrong to initialize all elements with a same value, which is not 0, in this way
        int visited[26];
        fill_n(visited, 26, -1); // assign -1 to all elements
        int curr_len = 0;
        int max_len = 0;
        int curr_index = 0;
        for(int i=0; i<s.length(); i++)
        {
            curr_index = s[i]- 'a';
            if(visited[curr_index] == -1 || i-visited[curr_index]>curr_len)
                curr_len++;
            else
            {
                if(curr_len > max_len)
                    max_len = curr_len;
                //update current substring length
                curr_len = i - visited[curr_index];
            }
            //update the position index of current visited character
            visited[curr_index] = i;
        } //for loop
        if(curr_len > max_len)
            max_len = curr_len;
        
        return max_len;
    }
};