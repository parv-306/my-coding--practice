
#include<stdio.h>
int main() {
    float basicPay, hra, ta, grossSalary, professionalTax, netSalary;
    printf("Enter basic pay: ");
    scanf("%f", &basicPay); 
    hra = 0.10 * basicPay;
    ta = 0.05 * basicPay;
    grossSalary = basicPay + hra + ta;
    professionalTax = 0.02 * grossSalary;
    netSalary = grossSalary - professionalTax;
    printf("Gross Salary: %.2f\n", grossSalary);
    printf("Professional Tax: %.2f\n", professionalTax);
    printf("Net Salary: %.2f\n", netSalary);
    return 0;
}   