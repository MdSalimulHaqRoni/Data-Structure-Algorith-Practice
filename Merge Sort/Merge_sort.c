#include<stdio.h>
void merge_sort(int A[], int left, int right)
{
    if(left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(A, left, mid);
    merge_sort(A, mid + 1, right);
    merge(A, left, mid, right);
}
void merge(int A[], int left, int mid, int right)
{
    int i;
    int index_a, index_l, index_r;
    int size_left, size_right;

    size_left = mid - left + 1;
    size_right = right - mid;

    int L[size_left], R[size_right];

    for(i = 0; i < size_left; i++)
    {
        L[i] = A[left + i];
    }
    for (i = 0; i < size_right; i++)
    {
        R[i] = A[mid + 1 + i];
    }
    index_l = 0;
    index_r = 0;
    for (index_a = left; index_l < size_left && index_r < size_right; index_a++)
    {
        if(L[index_l] < R[index_r])
        {
            A[index_a] = L[index_l];
            index_l += 1;
        }
        else
        {
            A[index_a] = R[index_r];
                         index_r += 1;
        }
    }
    while (index_l < size_left)
    {
        A[index_a] = L[index_l];
        index_l += 1;
        index_a += 1;
    }
    while (index_r < size_right)
    {
        A[index_a] = R[index_r];
        index_r += 1;
        index_a += 1;
    }

}
int main()
{
    int A[50], n, i;
    printf("Enter no of elements:");
    scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0; i<n; i++)
        scanf("%d",&A[i]);
    merge_sort(A,0,n-1);
    printf("\nSorted array is :");
    for(i=0; i<n; i++)
        printf("%d ",A[i]);
    return 0;

}
