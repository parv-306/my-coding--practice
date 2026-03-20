
#include<stdio.h>
int main() {
    int marks[5], sum = 0;
    float percentage;
    printf("Enter marks for 5 subjects:\n");
    for(int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        sum += marks[i];
    }
    percentage = (float)sum / 5;
    if(percentage >= 75) {
        printf("Grade: Distinction\n");
    } else if(percentage >= 60) {
        printf("Grade: First Division\n");
    } else if(percentage >= 50) {
        printf("Grade: Second Division\n");
    } else {
        printf("Grade: Third Division\n");
    }
    return 0;
}