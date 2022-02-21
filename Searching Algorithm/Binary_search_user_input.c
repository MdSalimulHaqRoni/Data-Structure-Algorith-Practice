#include<stdio.h>
int binary_search(int A[], int n, int x)
{
    int left, right, mid;
    left = 0;
    right = n-1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (A[mid] == x)
        {
            return mid;
        }
        if (A[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid -1;
        }
    }
    return -1;
}
int main()
{
    int A[30], n, x, position;
    int i;
    printf("Enter the Limit of Elements in Array:\n");
    scanf("%d", &n);
    printf("Enter %d Elements in Array: \n", n);
    for(i=0; i<n; i++)
        scanf("%d", &A[i]);
    printf("Enter Element To Search:\n");
    scanf("%d", &x);
    position = binary_search(A, n, x);
    if(position == -1)
    {
        printf("Element %d Not Found\n", x);
    }
    else
    {
        printf("Element %d Found at position %d\n", x, position + 1);
    }
    return 0;

}
