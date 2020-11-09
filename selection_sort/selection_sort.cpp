#include<iostream>
using namespace std;

#define Array_length(array) (sizeof(array) / sizeof(array[0]))

void Selection_sort(int A[], int length)
{
    int smallest_pos;
    int smallest_num;
    int temp;
    for(int i =0 ;i<length-1;i++)
    {
        smallest_pos = i;
        smallest_num = A[i];
        for(int j=i+1;j<length;j++)
        {
            if(A[j] < smallest_num)
            {
                smallest_num = A[j];
                smallest_pos = j;
            }
        }
        temp = A[i];
        A[i] = A[smallest_pos];
        A[smallest_pos] = temp;
    }
}

int main()
{
    int A[] = {6,2,3,1,9,10,15,13,12,17};
    int length = Array_length(A);
    Selection_sort(A,length);
    for(int i =0 ; i <length;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
