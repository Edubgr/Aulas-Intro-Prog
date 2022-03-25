#include<stdio.h>

int main(int argc, char* argv[]){
    int a,b;
    printf("Primeiro numero: ");
    scanf("%i",&a);
    printf("Segundo numero: ");
    scanf("%i",&b);

    if (a>b)
        printf("%i eh maior que %i.\n",a,b);
    else
        printf("%i eh maior que %i.",b,a);
    return 0;
}
