#include<stdio.h>
void insertion_sort(int A[], int n)
{
    int i, j, temp;
    for(i = 0; i < n; i++)
    {
        for(j = i - 1; j >= 0; j--)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
            else
                break;
        }
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
