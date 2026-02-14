#include<stdio.h>
int main() {
    int marks = 46;
    if(marks<=100 && marks>=90) {
        printf("grade is a");
    }
    else if(marks>=90 && marks<=80) {
        printf("grade is b");

    }
    else if(marks>=80 && marks<=70) {
        printf("grade is c");

    }
     else if(marks>=70 && marks<=60) {
        printf("grade is d");

    }
     else if(marks>=60 && marks<=50) {
        printf("grade is e ");
    }
    else {
        printf("grade is f");
    }

        

    
    return 0;

}
