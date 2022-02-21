#include<stdio.h>
int main()
{
    int A[] = {1,2,3,5,6,7,8,9,10,14,16,20,22,25,50,70,90};
    int item=10;

    int left, right, middle;
    left = 0;
    right = 17;

    while (left <= right)
    {
        middle = (left + right) /2;
        if (A[middle] == item)
        {
            printf("Item found at index : %d\n", middle);
            return 0;
        }
        else if(A[middle]<= item)
        {
            left = middle +1;
        }
        else
        {
            right = middle -1;
        }
    }
    printf("Item not found\n");
    return 0;
}
