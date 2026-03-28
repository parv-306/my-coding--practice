#include<stdio.h>
float num(int, int);

float num(int f,int c) {
    return (f - 32) * 5 / 9;
}

int main() {
    int f = 100, c;
    printf("temperature in celsius is %f", num(f, c));
    return 0;
}
    

    
