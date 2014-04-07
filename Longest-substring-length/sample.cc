class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last_visits[26];
        for (int i = 0; i < 26; ++i)
            last_visits[i] = -1;
        
        int curr_length = 0;
        int max_length = 0;
        for (int i = 0; i < s.size(); ++i) {
            int curr_index = s[i] - 'a';
            if (-1 == last_visits[curr_index] ||
                last_visits[curr_index] < i - curr_length) {
                ++curr_length;
            }
            else {
                max_length = (max_length > curr_length) ?
                             max_length : curr_length;
                curr_length = i - last_visits[curr_index];
            }
            
            last_visits[curr_index] = i;
        }
        
        max_length = (max_length > curr_length) ?
                     max_length : curr_length;
        
        return max_length;
        
        
    }
};