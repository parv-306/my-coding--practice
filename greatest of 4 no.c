#include<stdio.h>
int main() {
    int a=4,b=2,c=6,d=32;
    printf("the greatest of 4 numbers %d", a,b,c,d);
    if(a > b && a > c && a > d) {
        printf("the number is %d",a);
    }
  else if(b > a && b > c && b > d) {
     printf("the number is %d",b);

  }
        
  else if(c > a && c > b && c > d) {
    printf("the number is %d",c);

  }
         

  else {
        printf("the number %d",d);
    }
    return 0;

}
