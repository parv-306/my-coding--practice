// write a C program to take array input and print elements 

#include <stdio.h>


int main() {
    int arr[10];
    printf("Enter 10 Numbers: \n");
    for(int i = 0 ; i < 10 ; i++) {
        scanf("%d",&arr[i]);
    }

    printf("You Entered: \n");
    for(int i = 0; i < 10; i++) {
        printf("%d\n",arr[i]);
    }

    return 0;
}