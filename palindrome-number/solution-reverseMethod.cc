class Solution {
public:
    bool isPalindrome(int x) {
        long long reverse = 0;
        int input = x;
        if(input < 0)
            return false;
        else if(input>=0 && input<=9)
            return true;
        else
        {
            do{
                reverse = input%10 + reverse*10;
                input = input/10;
            }while((input/10 != 0) || (input%10 != 0));
            
            if(reverse == x)
                return true;
            else
                return false;
        }
    }
};