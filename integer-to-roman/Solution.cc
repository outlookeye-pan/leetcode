//I = 1;
//V = 5;
//X = 10;
//L = 50;
//C = 100;
//D = 500;
//M = 1000;

class Solution {
public:
    string intToRoman(int num) {
        
        string roman;
        int reminder = 0;
        int quotient = 0;
        
        //thousand bit
        quotient = num/1000;
        reminder = num%1000;
        if(quotient > 0)
        {
            roman.append(quotient, 'M');
        }
        
        //hundred bit
        quotient = reminder/100;
        reminder = reminder%100;
        if(quotient > 0 && quotient < 4)
            roman.append(quotient, 'C');
        if(quotient == 4)
            roman.append("CD");
        if(quotient > 4 && quotient < 9)
        {
            roman.append("D");
            roman.append(quotient-5, 'C');
        }
        if(quotient == 9)
            roman.append("CM");
            
        //ten bit
        quotient = reminder/10;
        reminder = reminder%10;
        if(quotient > 0 && quotient <4)
            roman.append(quotient, 'X');
        if(quotient == 4)
            roman.append("XL");
        if(quotient > 4 && quotient < 9)
        {
            roman.append("L");
            roman.append(quotient-5, 'X');
        }
        if(quotient == 9)
            roman.append("XC");
        
        //bit
        quotient = reminder/1;
        if(quotient > 0 && quotient < 4)
            roman.append(quotient, 'I');
        if(quotient == 4)
            roman.append("IV");
        if(quotient > 4 && quotient < 9)
        {
            roman.append("V");
            roman.append(quotient-5, 'I');
        }
        if(quotient == 9)
            roman.append("IX");
        
        return roman;
        
    }
};