#include<stdio.h>

int main(int argc, char* argv[]){
    float l,a;
    printf("Digite o tamanho do lado do quadrado: ");
    scanf("%f",&l);
    a=l*l;
    printf("\nA area do quadrado eh %.2f.\n",a);
    return 0;
}
