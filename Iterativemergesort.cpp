#include<iostream>

using namespace std;

// Iterative code for Merge sort

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


void IMergeSort( int A[], int n)
{
    int i, p, l, h, mid ;
    
    for(p = 2; p<=n; p = p*2)
    {
        for(i=0; i+p-1<n; i = i+p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A,l,mid,h);
        }
        if(n-1>p/2)
        {
          l = i;
          h = i+p-1;
          mid = (l+h)/2;
          Merge(A,l,mid,n-1);
        }
    }

    if(p/2<n)
    {
        Merge(A,0,p/2-1,n-1);
    }

}
int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int n = sizeof(A)/sizeof(int);

    IMergeSort(A,n);

    for(int i = 0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }


    return 0;
}