#include<iostream>

using namespace std;

#define Array_length(array) (sizeof(array)/sizeof(array[0]))

void Bubble_sort(int A[],int length)
{

    int temp;
    for(int i=0;i<length;i++)
    {
        for(int j =0;j<length-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

int main(void)
{
    int A[] = {6,2,3,1,9,10,15,13,12,17};
    int length = Array_length(A);
    Bubble_sort(A,length);
    for(int i =0 ;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}
