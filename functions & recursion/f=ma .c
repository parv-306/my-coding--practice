 #include<stdio.h>

float num(float m, float g) {
    return m * g;
}

int main() {
    float m = 10, g = 9.8;

    printf("Force is %.2f", num(m, g));

    return 0;
}