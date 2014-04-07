class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> results;
        vector<int>::size_type index1, index2;
        bool flag = 0;
        for(index1 = 0; index1 != numbers.size(); ++index1)
        {
            for(index2 = (index1+1); index2 != numbers.size(); ++index2)
            {
                if(numbers[index1] + numbers[index2] == target)
                {
                    flag = 1;
                    results.push_back(index1+1);
                    results.push_back(index2+1);
                }
                else
                    continue;
            }
            
        }
        if(flag == 0)
          cout << "Could not find two numbers to sum up as the target number."<< endl;
        return results;
    }
};