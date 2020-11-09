#include<iostream>

using namespace std;

#define Array_length(array) (sizeof(array)/sizeof(array[0]))

void Merge(int A[], int L[],int l_count, int R[],int r_count)
{
    int left = 0;
    int right = 0;
    int total = 0;
    while(l_count!=0 && r_count !=0)
    {
        if(L[left] > R[right])
        {
            A[total++] = R[right++];
            r_count = r_count - 1;
        }
        else
        {
            A[total++] = L[left++];
            l_count = l_count -1;
        }
    }
    while(l_count >0)
    {
        A[total++] = L[left++];
        l_count = l_count -1;
    }

    while(r_count >0)
    {
        A[total++] = R[right++];
        r_count = r_count -1;
    }
}

void Merge_sort(int A[],int length)
{
    if(length == 1)
    {
        return;
    }
    int mid = length/2;
    int* L = new int[mid];
    int* R = new int[length-mid];
    for(int i =0;i<length;i++)
    {
        if(i<mid)
        {
            L[i] = A[i];
        }
        else
        {
            R[i-mid] = A[i];
        }

    }

    Merge_sort(L,mid);
    Merge_sort(R,length-mid);
    Merge(A,L,mid,R,length-mid);
}


int main(void)
{
    int A[] = {6,2,3,1,9,10,15,13,12,17};
    int length = Array_length(A);
    Merge_sort(A,length);

    for(int i =0 ;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

