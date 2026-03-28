#include<stdio.h>
float average(int , int , int );


    
float average(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

int main() {
    int a = 10, b = 20, c = 30;
    printf("average of a,b,c is %f", average(a, b, c));
    return 0;
    

}
