#include<iostream>

using namespace std;


void swap ( int &A, int &B)
{
    int temp  = A;
    A = B;
    B = temp;
}



int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    
    do 
    {
        do{i++;}while(A[i]<=pivot); // So if its less or equal to pivot it will keep on moving.
        do{j--;}while(A[j]>pivot); // So if it is greater than pivot, it will keep moving and will stop if A[j] is less or equal.
        
        if(i<j)
        {
            swap(A[i],A[j]);
        }
    }  while(i<j);

    swap(A[l], A[j]);
    return j;
    
}


void QuickSort (int A[], int l, int h)
{
    int j;
    if(l<h)
    {
        j = partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}










int main()
{
    int A[] = {11,13,7,12,16,9,24,5,10,3, INT32_MAX};
    int n = sizeof(A)/sizeof(int);
    

    QuickSort(A,0,n-1);

    
    for(int i = 0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }


    return 0;
}