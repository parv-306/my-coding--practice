#include<stdio.h>
int main() {
    int n  = 4;
    int* p = &n;
    printf("the address i is %p", &n);
    printf("the value of  i is %d", n);
}