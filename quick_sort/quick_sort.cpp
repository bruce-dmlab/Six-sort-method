#include<iostream>

using namespace std;
#define Array_length(array) (sizeof(array) / sizeof(array[0]))

void Num_swap(int* first, int* second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

void Quick_sort(int A[],int l_bound,int r_bound)
{
    if(l_bound>=r_bound)
    {
        return;
    }

    int pivot = A[l_bound];
    int left = l_bound+1;
    int right = r_bound;
    int temp;
    int a;

    while(1)
    {
        while(left<=r_bound)
        {
            if(A[left] > pivot)
            {
                break;
            }
            left = left + 1;
        }

        while(right >l_bound)
        {
            if(A[right] < pivot)
            {
                break;
            }
            right = right - 1;
        }

        if(left<=right)
        {
            temp = A[left];
            A[left] = A[right];
            A[right] = temp;
            //Num_swap(&A[left],&A[right]);
        }
        else
        {
            break;
        }
    }

    temp = A[l_bound];
    A[l_bound] = A[right];
    A[right] = temp;
    //Num_swap(&A[l],&A[right]);
    Quick_sort(A,l_bound,right-1);
    Quick_sort(A,right+1,r_bound);


}

int main(void)
{
    int A[] = {6,2,3,1,9,10,15,13,12,17};
    int length = Array_length(A);
    int left =0;
    int right = length -1;
    Quick_sort(A,left,right);


    for(int i =0;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}
