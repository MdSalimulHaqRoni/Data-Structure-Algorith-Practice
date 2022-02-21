#include<stdio.h>
void selection_sort(int A[], int n)
{
    int i, j, index_min, temp;
    for (i = 0; i < n-1; i++)
    {
        index_min = i;
        for (j = i + 1; j < n; j++)
        {
            if(A[j] < A[index_min])
            {
                index_min = j;
            }
        }
        if(index_min != i)
        {
            temp = A[i];
            A[i] = A[index_min];
            A[index_min] = temp;
        }
    }
}
int main()
{
    int A[30], n;
    int i;
    printf("\nEnter number of array: ");
    scanf("%d", &n);
    printf("\nEnter elements of array:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);
    selection_sort(A, n);
    printf("\nAfter sorting: ");
    for(i = 0; i < n; i++)
        printf("\n%d", A[i]);
    return 0;
}
