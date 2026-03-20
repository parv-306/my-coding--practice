
#include <stdio.h>
#include <math.h>
int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
void primeFactors(int num) {
    printf("Prime factors of %d: ", num);
    for (int i = 2; i <= num; i++) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }
    printf("\n");
}
unsigned long long factorial(int num) {
    if (num == 0 || num == 1) return 1;
    unsigned long long fact = 1;
    for (int i = 2; i <= num; i++) {
        fact *= i;
    }
    return fact;
}
int main() {
    int number, choice;
    printf("Enter an integer number: ");
    scanf("%d", &number);
    printf("Menu:\n");
    printf("1. Calculate the square root of the number\n");
    printf("2. Calculate the square of the number\n");
    printf("3. Calculate the cube of the number\n");
    printf("4. Check whether the number is prime\n");
    printf("5. Find the factorial of the number\n");
    printf("6. Find the prime factors of the number\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            if (number < 0) {
                printf("Square root is not defined for negative numbers.\n");
            } else {
                printf("Square root of %d is %.2f\n", number, sqrt(number));
            }
            break;
        case 2:
            printf("Square of %d is %d\n", number, number * number);
            break;
        case 3:            
            printf("Cube of %d is %d\n", number, number * number * number);
            break;
        case 4:
            if (isPrime(number)) {
                printf("%d is a prime number.\n", number);
            } else {
                printf("%d is not a prime number.\n", number);
            }
            break;
        case 5:
            if (number < 0) {
                printf("Factorial is not defined for negative numbers.\n");
            } else {
                printf("Factorial of %d is %llu\n", number, factorial(number));
            }
            break;
        case 6:
            if (number < 2) {
                printf("Prime factors are not defined for numbers less than 2.\n");
            } else {
                primeFactors(number);
            }
            break;
        default:
            printf("Invalid choice. Please select a valid option from the menu.\n");
    }   return 0;   

}