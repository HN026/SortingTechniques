#include<iostream>

using namespace std;

int main()
{
     
    int A[] = {11, 13, 7, 2, 6, 9, 4, 5, 10, 3};
    int n = sizeof(A) / sizeof(int);


    for(int i = 0; i< n; i++)
    {
        cout<<A[i]<<" ";
    }


    return 0;
}