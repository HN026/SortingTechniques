#include<iostream>

using namespace std;

// It has a concept of gap = [n/2] where gap is an integer.
// It's just like insertion sort but is more limited shifting than that.
// it takes nlog2n times where log2n is no of passes and n is the number of scans.
// It sometimes also analysed as n^3/2 or n^5/3.
// Shell sort is also adaptive and doesn't take extra space.


void ShellSort(int A[], int n)
{
    int gap, i, j,temp;
    for(gap = n/2; gap>=1; gap/=2)
    {
        for(i = gap; i<n; i++)
        {
            temp = A[i];
            j = i-gap;
            while(j>=0 && A[j]>temp)
            {
                A[j+gap] = A[j];
                j=j-gap;
            }
            A[j+gap] = temp;
        }
    }
}


int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int n = sizeof(A)/sizeof(int);

    ShellSort(A,n);

    for(int i = 0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }

    return 0;
}