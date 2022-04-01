#include<stdio.h>
#include<math.h>

int main(int argc, char* argv[]){
    double a,b,c;
    printf("Escreva os coeficientes A: ");
    scanf("%i",&a);
    printf("B: ");
    scanf("%i",&b);
    printf("C: ");
    scanf("%i",&c);

    printf("A equacao eh %ix^2+%ix+%i\n",a,b,c);
    double delta=b*b-4*a*c;
    printf("Delta eh: %.2f\n",delta);
    if (delta>=0){
        double x1=(-b+sqrt(delta))/(2*a);
        double x2=(-b-sqrt(delta))/(2*a);
        printf("x' eh: %.2f.\n",x1);
        printf("x'' eh: %.2f.\n",x2);
    }
    else
        printf("Nao ha raizes reais\n",a,b);

    return 0;
}

