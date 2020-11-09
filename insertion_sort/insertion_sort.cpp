#include<iostream>
using namespace std;

#define Array_length(array) (sizeof(array) / sizeof(array[0]))

void Insertion_sort(int A[], int length)
{
    int temp;
    for(int i=1;i<length;i++)
    {
        temp = A[i];
        int j;
        for(j = i-1;j>=0;j--)
        {
            if(A[j] > temp)
            {
                A[j+1] = A[j];
            }
            else
            {
                A[j+1] = temp;
                break;
            }
        }

        if(j == -1)
        {
            A[j+1] = temp;
        }
    }
}

int main()
{
    int A[] = {6,2,3,1,9,10,15,13,12,17};
    int length = Array_length(A);
    Insertion_sort(A,length);
    for(int i =0;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}
