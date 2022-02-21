#include<stdio.h>
int main()
{
    int i;
    int A[] = {10,20,30,40,50,60,70,80,90,100};
    int n = 40;
    for (i = 0; i < 10; i++){
        if (A[i] == n){
            printf("Item is found index: %d",i);
            return;
        }
    }

    printf("Item is not found");
    return 0;

}
