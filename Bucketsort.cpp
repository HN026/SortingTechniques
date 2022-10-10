#include<iostream>

using namespace std;

// In this we make an array of linked lists
// Time complexity is O(n).

int Max(int A[], int n)
{
    int max = INT32_MIN;
    for(int i = 0; i<n; i++)
    {
        if(A[i]>max)
        {
            max = A[i];
        }
    }
    return max;
}

class Node{
    public: 
    int value;
    Node *next;
};

void Insert(Node**ptrBins, int idx)
{
    Node *temp = new Node;
    temp->value = idx;
    temp->next = nullptr;
    if(ptrBins[idx] == nullptr)
    {
        // ptrBins is head ptr
        ptrBins[idx] = temp;
    }
    else
    {
        Node *p = ptrBins[idx];
        while(p->next != nullptr)
        {
            p = p->next;
        }
        p->next = temp;
    }
}


int Delete(Node **ptrBins, int idx)
{
    Node *p = ptrBins[idx]; // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}

void BinSort (int A[], int n)
{
    int max  = Max(A, n);
    
    // Create bins array
    Node **bins = new Node*[max+1];

    // Initialise bins array with nullptr
    for(int i = 0; i<max+1; i++)
    {
        bins[i] = nullptr;
    }

    // Update count array values based on A values
    for(int i = 0; i<n; i++)
    {
        Insert(bins, A[i]);
    }

    // Update A with sorted elements
    int i = 0; 
    int j = 0;
    while(i<max+1)
    {
        while(bins[i]!=nullptr){
            A[j++] = Delete(bins, i);
        }
        i++;
    }

    // Delete heap memory
    delete [] bins;
}


int main()
{

    int A[] = {2,3,8,12,3,6,7,10};
    int n = sizeof(A)/sizeof(int);

    BinSort(A,n);

    for(int i = 0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }

    return 0;
}