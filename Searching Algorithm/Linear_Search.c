#include<stdio.h>
int linear_search(int A[], int n, int x)

{
    int i;

    for(i = 0; i < n; i++){

        if (A[i] == x){
            return i;
        }
    }
     i = -1;
     return i;
}
int main()
{
    int n, i, search, position, x;
    int A[] = {10,20,30,40,50,60,70,80,90,100};

   printf("Input number of elements in array\n");
   scanf("%ld", &n);

   printf("Input %d numbers\n", n);

   for (i = 0; i < n; i++)
      scanf("%ld", &A[i]);

   printf("Input a number to search\n");
   scanf("%ld", &search);

  linear_search(A, n, x);

   if (position == -1)
      printf("%d isn't present in the array.\n", search);
   else
      printf("%d is present at location %d.\n", search, position+1);
    return 0;
}
