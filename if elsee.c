#include<stdio.h>
int main() {
    int marks1, marks2, marks3;
    printf("enter  the marks1\n");
    scanf("%d", &marks1);
    printf("enter  the marks2\n");
    scanf("%d", &marks2);
    printf("enter  the marks3\n");
    scanf("%d", &marks3);

    if(marks1 <33 || marks2 <33 || marks3<33) {
        printf("you are fail in individual subject");

    

    }
    else if((marks1 + marks2 + marks3)/3 < 40) {
        printf("you are failed due to less marks");

    }
    else {
        printf("you are pass");
    }
    
    

    
    return 0;

}
