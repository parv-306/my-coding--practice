#include<stdio.h>
int main() {
    char ch = 'a';
    printf("the  character is %c\n", ch);
    printf("the alue of character is %d\n", ch);
    if(ch >= 97 && ch <= 122){
        printf("the case is upper case");
    }
    else {
        printf("not a lower  case");
    }
    
    return 0;

}
