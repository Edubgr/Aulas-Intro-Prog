#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[]){
    int a,b,c;
    printf("Lado A: ");
    scanf("%i",&a);
    printf("Lado B: ");
    scanf("%i",&b);
    printf("Lado C: ");
    scanf("%i",&c);

    printf("O triangulo tem lado %i, %i e %i.\n",a,b,c);

    if (a+b>c && a+c>b && b+c>a){
        printf("Eh um triangulo.\n");
    }else{
        printf("Nao eh um triangulo.\n",a,b);
        return 0;
    }
    if (a==b && b==c)
        printf("Eh equilatero.\n");
    else {
        if (a==b && b==c && a==c)
            printf("Eh isoceles.\n");
        else
            printf("Eh escaleno.\n");
    }
    double p=(a+b+c)/2;
    double area=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("A area eh: %.2f.",area);
    return 0;
}

