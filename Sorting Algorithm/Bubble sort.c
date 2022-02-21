#include<stdio.h>
void bubble_sort(int A[], int n)
{
    int i, j, temp;
    for(i = 0; i < n; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int A[100], n, i;
    printf("Enter number of elements in the array:\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    bubble_sort(A, n);
    printf("Printing the sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", A[i]);
    return 0;
}
