#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    double searchOneArrayMedian(int array[], int first, int last) {
        double middle;
        int size = last - first + 1;
        if(size == 1)
        {
            middle = array[first];
        }
        else
        {
            if(size%2 == 1)
            {
                middle = array[(size-1)/2];                
            }
            else
            {
                middle = (array[size/2-1] + array[size/2])/2.0;
            }
        }
        return middle;
    } //searchArray
    
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        double a_mid, b_mid;
        int a_first = 0, b_first = 0;
        int a_last = m-1, b_last = n-1;
        double median;

        if(m == 0 && n == 0)
        {
            cout << "Two empty arrays, no median."<<endl;
        }
        else if(m == 0 && n > 0)
        {
            median = searchOneArrayMedian(B, b_first, b_last);
        }
        else if(m > 0 && n == 0)
        {
            median = searchOneArrayMedian(A, a_first, a_last);
        }
        else
        {
            //while((a_last-a_first != 1) && (b_last-b_first != 1))
            do
            {
                a_mid = searchOneArrayMedian(A, a_first, a_last);
                b_mid = searchOneArrayMedian(B, b_first, b_last);
                if(a_mid <b_mid)
                {
                    if((a_last-a_first+1)>1)
                    {
                        a_first = floor((a_last-a_first+1)/2.0)+ a_first;
                    }
                    if((b_last-b_first+1)>1)
                    {
                        b_last = floor((b_last -b_first)/2.0) + b_first;
                    }
                }
                else if(a_mid > b_mid)
                {
                    if((a_last-a_first+1)>1)
                    {
                        a_last = floor((a_last-a_first)/2.0) + a_first;
                    }
                    if((b_last-b_first+1)>1)
                    {
                        b_first = floor((b_last -b_first+1)/2.0) + b_first;
                    }
                }
                else
                    return a_mid;
            } while((a_last-a_first > 0) || (b_last-b_first > 0));
//            median = (max(A[a_first], A[a_last]) + min(B[b_first], B[b_last]))/2.0;   
            median = (A[a_first]+B[b_first])/2.0;
        }

        return median;       
    } //end of findMedianSortedArrays

};