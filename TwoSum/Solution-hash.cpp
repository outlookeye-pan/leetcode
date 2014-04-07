//Attention the condition (&& mymap.find(target-numbers[index])->second != index) in line 16.
//To avoid the special case such as, numbers are {4,2,6}, target is 8. The map::find function might find "4" twice since 4+4=8
//So add constraint that avoid add a same number twice to reach the target value.

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> results;
        map<int, int> mymap;
        //store numbers in hash map. number as key, and position as value.
        for(int index = 0; index < numbers.size(); index++)
        {
            mymap.insert(pair<int, int>(numbers[index], index));
        }
        
        for(int index = 0; index < numbers.size(); index++)
        {
            if(mymap.find(target - numbers[index]) != mymap.end() && mymap.find(target-numbers[index])->second != index)
            {
                if(index < mymap[target-numbers[index]])
                {
                    results.push_back(index+1);
                    results.push_back(mymap[target-numbers[index]]+1);
                }
                else
                {
                    results.push_back(mymap[target-numbers[index]]+1);
                    results.push_back(index+1);
                }
                break;
            }
        }
        return results;
    }
};