#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Bubble(int A[], int n)
{
    int flags;
    for (int i = 0; i < n - 1; i++)
    {
        flags = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                flags = 1;
            }
        }
        if(flags==0)
        {
            break;
        }

    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = sizeof(A) / sizeof(int); // No of elements.
    Bubble(A, n);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    

    return 0;
}