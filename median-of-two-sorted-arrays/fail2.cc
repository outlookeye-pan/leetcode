//fial for test case: A=[1,2,3], B=[1,2,2]
#include <math.h>
#include <algorithm>
#include <iostream>

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
                middle = (array[first+size/2-1] + array[first+size/2])/2.0;
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

            do
            {
                cout << "a_mid" << a_mid << ";   b_mid" << b_mid << endl;
                a_mid = searchOneArrayMedian(A, a_first, a_last);
                b_mid = searchOneArrayMedian(B, b_first, b_last);
                if(a_mid <b_mid) //back half of A, front half of B
                {
                    
                    if((a_last>a_first) && (b_last>b_first))
                    {
                        a_first = floor((a_last-a_first+1)/2.0)+ a_first;
                        b_last = floor((b_last -b_first)/2.0) + b_first;
                    }
                    else
                    {
                        if((a_last-a_first)==0 && (b_last-b_first)>0)
                        {
                            if(a_mid < B[b_first])
                            {
                                b_last = floor((b_last -b_first)/2.0) + b_first;
                                return median = searchOneArrayMedian(B, b_first, b_last);
                            }
                            else
                            {
                                a_first = floor((a_last-a_first+1)/2.0)+ a_first;
                                b_last = floor((b_last -b_first)/2.0) + b_first;
                            }
                        }
                        if((a_last-a_first)>0 && (b_last-b_first)==0)
                        {
                            if(A[a_last] < b_mid)
                            {
                                a_first = floor((a_last-a_first+1)/2.0)+ a_first;
                                return median = searchOneArrayMedian(A, a_first, a_last);
                            }
                            else
                            {
                                a_first = floor((a_last-a_first+1)/2.0)+ a_first;
                                b_last = floor((b_last -b_first)/2.0) + b_first;
                            }
                        }
                    }
                }
//                else if(a_mid >= b_mid) //front half of A, back half of B
                else
                {
                    cout << "a_mid" << a_mid << ";   b_mid" << b_mid << endl;
                    if((a_last-a_first)>0 && (b_last-b_first)>0)
                    {
                        a_last = (a_last-a_first)/2 + a_first;
                        b_first = (b_last - b_first+1)/2 + b_first;
                    }
                    else
                    {
                        if((a_last-a_first)==0 && (b_last-b_first)>0)
                        {
                            if(a_mid > B[b_last])
                            {
                                b_first = floor((b_last -b_first+1)/2.0) + b_first;
                                return median = searchOneArrayMedian(B, b_first, b_last);
                            }
                            else
                            {
                                a_last = floor((a_last-a_first)/2.0) + a_first;
                                b_first = floor((b_last -b_first+1)/2.0) + b_first;
                            }
                        }
                        if((a_last-a_first)>0 && (b_last-b_first)==0)
                        {
                            if(A[a_first] > b_mid)
                            {
                                a_last = floor((a_last-a_first)/2.0) + a_first;
                                return median = searchOneArrayMedian(A, a_first, a_last);
                            }
                            else
                            {
                                a_last = floor((a_last-a_first)/2.0) + a_first;
                                b_first = floor((b_last -b_first+1)/2.0) + b_first;
                            }
                        }
                    }
                }
 //               else
 //                   return a_mid;
            } while((a_last-a_first > 0) || (b_last-b_first > 0));
            median = (A[a_first]+B[b_first])/2.0;
        }
        return median;       
    } //end of findMedianSortedArrays
};

int main()
{
    int A[] = [1, 2, 3];
    int B[] = [1, 2, 2];
    Solution sol = new Solution();
    cout << sol->findMedianSortedArrays(A, 3, B, 3);
    return 1;
}