#include<iostream>

using namespace std;

// As this method is recursive in nature, it will be using a stack, total space complexity in this method will be 2n + logn & n + logn is the extra space that is required by the recursive merge sort algorithm.


void Merge( int A[], int l, int mid, int h)
{
    int i = l,j=mid+1,k=l;
    int B[100];
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    for(;i<=mid; i++)
    {
        B[k++] = A[i];
    }
    for(;j<=h; j++)
    {
        B[k++] = A[j];
    }

    for(i=l;i<=h;i++)
    {
        A[i] = B[i];
    }
}


void RMergeSort(int A[], int l, int h)
{
    int mid;
    if(l<h)
    {
        mid = (l+h)/2;
        RMergeSort(A,l,mid);
        RMergeSort(A,mid+1,h);
        Merge(A, l, mid , h);
    }
}

int main()
{
     
    int A[] = {11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
    int n = sizeof(A) / sizeof(int);

    RMergeSort(A,0, n-1);

    for(int i = 0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    return 0;
}