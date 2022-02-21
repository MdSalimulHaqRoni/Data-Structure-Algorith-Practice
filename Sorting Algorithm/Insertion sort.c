#include<stdio.h>
void insertion_sort(int A[], int n)
{
    int i, j, item;
    for (i = 0; i< n; i++)
    {
        item = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > item)
        {
            A[j + 1] = A[j];
            j = j - 1;
        }
        A[j + 1] = item;
    }
}
int main()
{
    int A[100], n, i;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    printf("Enter the elements : \n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    insertion_sort(A, n);
    printf("The sorted elements are : \n");
    for (i = 0; i < n; i++)
        printf("%d\n", A[i]);
    return 0;
}
