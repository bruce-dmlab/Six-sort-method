#include<iostream>
#include<vector>
#include <climits>

using namespace std;
#define Array_length(array) (sizeof(array) / sizeof(array[0]))

int min_pos(int a,int b)
{
    if(a>=b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Heapify(int index,int A[],int length)
{
    int l_child = INT_MAX,r_child = INT_MAX;
    int temp;

    if((index * 2+1)<length)
    {
        l_child = A[index * 2+1];
    }

    if((index * 2+2)<length)
    {
        r_child = A[index * 2+2];
    }


    if(r_child > l_child)
    {
        if(A[index] > l_child)
        {
            temp = A[index];
            A[index] = A[index * 2+1];
            A[index * 2+1] = temp;
            return Heapify(index * 2+1,A,length);
        }
    }
    else
    {
        if(A[index] > r_child)
        {
            temp = A[index];
            A[index] = A[index * 2+2];
            A[index * 2+2] = temp;
            return Heapify(index * 2+2,A,length);
        }
    }

    return;

}

void Heap_sort(int A[],int length)
{
    for(int i = length -1 ;i >=0;i--)
    {
        Heapify(i,A,length);
    }


    vector<int> result;
    for(int i = 0;i<length;i++)
    {
        result.push_back(A[0]);
        A[0] = A[length-i-1];
        Heapify(0,A,length-i-1);
    }

    for(int i =0;i<result.size();i++)
    {
        A[i] = result[i];
    }
}

int main(void)
{
    int A[] = {6,2,3,1,9,10,15,13,12,17};
    int length = Array_length(A);

    Heap_sort(A,length);


    for(int i =0;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}
