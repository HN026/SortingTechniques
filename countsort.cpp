#include<iostream>

using namespace std;

// Time complexity is O(n) and it consumes extra space of the order of n.

int main()
{   
    int A[] = {11,13,7,12,16,9,24,5,10,3};
    int n = sizeof(A)/sizeof(int);
    

    
    for(int i = 0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }

    return 0;
}